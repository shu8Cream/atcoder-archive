/**
*    author:  shu8Cream
*    created: 12.03.2022 20:33:22
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
const ll INF = 8e16;

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
    int from, to;
    T cost;
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
    int n,m; cin >> n >> m;
    vvi dist(n+1,vi(n+1,INF));
    vvi dp(n+1,vi(n+1,INF));
    vector<tuple<ll,ll,ll>> vec(m);
    rep(i,m){
        int a,b; ll c; cin >> a >> b >> c;
        a--; b--;
        dist[a][b] = c;
        dist[b][a] = c;
        vec[i] = {a,b,c};
    }
    dp = dist;
    rep(k,n)rep(i,n)rep(j,n){
        chmin(dp[i][j],dp[i][k]+dp[k][j]);
    }

    int ans = 0;
    rep(i,m){
        auto[a,b,c] = vec[i];
        int f = 0;
        rep(j,n){
            if(dp[a][j]+dp[j][b]<=c) f = 1;
        }
        ans+=f;
    }
    cout << ans << endl;
}