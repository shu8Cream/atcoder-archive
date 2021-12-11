/**
*    author:  shu8Cream
*    created: 11.12.2021 20:44:50",
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


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    if(n<=m){
        cout << "No" << endl;
        return 0;
    }
    vvi to(n);
    UnionFind uf(n);
    bool f = true;
    rep(i,m){
        int u,v; cin >> u >> v;
        u--;v--;
        to[u].push_back(v);
        to[v].push_back(u);
        if(uf.find(u)==uf.find(v)) f = false;
        uf.merge(u,v);
    }
    rep(i,n)if(sz(to[i])>=3) f = false;
    int cnt = 0;
    rep(i,n)if(sz(to[i])<=1) cnt++;
    if(f && cnt<=1) f = false;

    cout << (f ? "Yes" : "No") << endl;
}