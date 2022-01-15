/**
*    author:  shu8Cream
*    created: 15.01.2022 22:21:18
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

template <class T> string to_string(T s);
template <class S, class T> string to_string(pair<S, T> p);
string to_string(char c) { return string(1, c); }
string to_string(string s) { return s; }
string to_string(const char s[]) { return string(s); }

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

template<typename T>
struct edge {
    ll from, to;
    T cost;
    ll id;
    bool operator<(const edge &other) const {
        return cost < other.cost;
    }
};

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
        if(par[x] > par[y]) swap(x,y);
        for(auto p : mp[y]){
            mp[x][p.first] += p.second;
        }
        mp[y] = map<int,int>();
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    bool same(int x, int y) {return find(x) == find(y);}
    int size(int x) {return -par[find(x)];}
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,m,q; cin >> n >> m >> q;
    vector<edge<ll>> vec(m+q);
    rep(i,m){
        ll s,t,w; cin >> s >> t >> w;
        s--; t--;
        vec[i] = {s,t,w,i};
    }
    rep(i,q){
        ll u,v,w; cin >> u >> v >> w;
        u--; v--;
        edge<ll> t = {u,v,w,m+i};
        vec[i+m] = t;
    }
    sort(all(vec), [](const edge<ll> &a, const edge<ll> &b) {
        return a.cost < b.cost;
    });
    UnionFind uf(n);
    set<ll> ids;
    ll res = 0;
    for(edge<ll> &e : vec){
        if(!uf.same(e.to,e.from)){
            if(e.id>=m){
                ids.insert(e.id);
                continue;
            }
            uf.merge(e.to, e.from);
            res += e.cost;
            ids.insert(e.id);
        }
    }
    vi ans(q);
    for(auto p:ids){
        if(p>=m) ans[p-m] = 1;
    }
    rep(i,q){
        if(ans[i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}