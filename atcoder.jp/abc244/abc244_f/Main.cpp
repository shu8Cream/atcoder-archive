/**
*    author:  shu8Cream
*    created: 20.03.2022 21:47:30
**/

#include <bits/stdc++.h>
using namespace std;
#define overload3(a,b,c,d,...) d
#define rep1(i,n) for (int i=0; i<(n); i++)
#define rep2(i,a,n) for (int i=(a); i<(n); i++)
#define rep(...) overload3(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)
#define rrep1(i,n) for (int i=(n-1); i>=0; i--)
#define rrep2(i,a,n) for (int i=(n-1); i>=(a); i--)
#define rrep(...) overload3(__VA_ARGS__, rrep2, rrep1)(__VA_ARGS__)
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

ll dp[1<<17][17];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    vvi to(n);
    vector<P> edge(m);
    rep(i,m){
        int u,v; cin >> u >> v;
        u--; v--;
        edge[i] = {u,v};
        to[u].push_back(v);
        to[v].push_back(u);
    }
    fill(&dp[0][0],&dp[0][0]+(1<<17)*17,INF);
    
    queue<P> q;
    rep(i,n){
        dp[1<<i][i] = 1;
        q.push({1<<i,i});
    }

    while(!q.empty()){
        auto[bit,v] = q.front(); q.pop();
        for(auto nv : to[v]){
            int new_bit = bit^(1<<nv);
            if(dp[new_bit][nv]!=INF) continue;
            dp[new_bit][nv] = dp[bit][v] + 1;
            q.push({new_bit,nv});
        }
    }

    ll ans = 0;
    rep(i,1,1<<n){
        ll tmp = INF;
        rep(j,17) chmin(tmp,dp[i][j]);
        ans += tmp;
        // if(dp[i]==INF) cout << "INF" << endl;
        // else cout << dp[i] << endl;
    }
    cout << ans << endl;
}