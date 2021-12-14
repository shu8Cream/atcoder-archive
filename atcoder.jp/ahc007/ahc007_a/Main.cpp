/**
*    author:  shu8Cream
*    created: 14.12.2021 08:53:41",
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=(n-1); i>=0; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;
const ll INF = 8e18;

template<class T> inline bool chmax(T& a, T b) {
    if (a < b) { a = b; return true; }
    return false;
}
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) { a = b; return true; }
    return false;
}

template <class T>
string to_string(T v) {
  if (v.empty()) return "{}";
  string ret = "{";
  for (auto x : v) ret += to_string(x) + ",";
  ret.back() = '}';
  return ret;
}
template <class S, class T>
string to_string(pair<S, T> p) {
  return "{" + to_string(p.first) + ":" + to_string(p.second) + "}";
}

void debug_out() { cout << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cout << to_string(H) << " ";
    debug_out(T...);
}

#ifdef _DEBUG
#define debug(...) debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

const int N = 400;
const int M = 1995;
vector<P> vertex(N);
vi isUse(M);

struct UnionFind{
    vector<int> par;
    vector<map<int, int>> mp;
    UnionFind(int n=0): par(n, -1), mp(n) {}
    int find(int x){
        if(par[x] < 0) return x;
        return par[x] = find(par[x]);
    }
    bool merge(int x, int y){
        x = find(x); y = find(y);
        if(x == y) return false;
        if(par[x] > par[y]) swap(x,y); //マージテク
        for(auto p : mp[y]){
            mp[x][p.first] += p.second;
        }
        mp[y] = map<int,int>(); //メモリの解放
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    bool same(int x, int y) {return find(x) == find(y);}
    int size(int x) {return -par[find(x)];}
};

struct edge {
    int from, to, idx, cost;
    edge(){}
    edge(const int from, const int to, const int idx, const int cost) : from(from), to(to), idx(idx), cost(cost) {}
};

vector<edge> Kru(M);
void Input(){
    rep(i,N){
        int x,y; cin >> x >> y;
        vertex[i] = {x,y};
    }
    rep(i,M){
        int u,v; cin >> u >> v;
        auto [x1,y1] = vertex[u]; 
        auto [x2,y2] = vertex[v]; 
        int dist = round(sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)));
        Kru[i] = {u,v,i,dist};
    }
}

ll kruskal(vector<edge> &Ed, double exp){
    UnionFind uf(N);
    ll res = 0;
    vector<edge> ed;
    for(edge p : Ed){
        if(isUse[p.idx]==1){
            uf.merge(p.from,p.to);
            res+=p.cost;
        }else if(isUse[p.idx]==0){
            p.cost = ll(exp*p.cost);
            ed.emplace_back(p);
        }
    }
    sort(all(ed), [](const edge &a, const edge &b) {
        return a.cost < b.cost;
    });

    for(edge p: ed){
        if(uf.same(p.from,p.to)) continue;
        uf.merge(p.from,p.to);
        res += p.cost;
    }
    if(uf.size(0)!=N) return 1e9;
    return res;
}


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    #ifdef _DEBUG
    FILE *fp;
    fp = fopen("./tools/out/0000.txt", "w");
    #endif
    Input();

    rep(i,M){
        ll l; cin >> l;
        Kru[i].cost = l;
        double exp = 2.0;
        isUse[i] = -1;
        ll tmp1 = kruskal(Kru,exp);
        isUse[i] = 1; 
        ll tmp2 = kruskal(Kru,exp); 
        int exp2 = sqrt(M-i);
        if(tmp1>tmp2){
            #ifdef _DEBUG
            fprintf(fp, "%d\n", 1);
            #else
            cout << 1 << endl;
            #endif
            isUse[i] = 1;
        }else{
            #ifdef _DEBUG
            fprintf(fp, "%d\n", 0);
            #else
            cout << 0 << endl;
            #endif
            isUse[i] = -1;
        }
    }
    #ifdef _DEBUG
    fclose(fp);
    #endif
}