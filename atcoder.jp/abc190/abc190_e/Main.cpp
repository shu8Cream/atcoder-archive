/**
*    author:  shu8Cream
*    created: 20.10.2021 20:39:28
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
const ll INF = 2e18;

template<class T> inline bool chmax(T& a, T b) {
    if (a < b) { a = b; return true; }
    return false;
}
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) { a = b; return true; }
    return false;
}

void debug_out() { cout << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
cout << H << " ";
debug_out(T...);
}

#ifdef _DEBUG
#define debug(...) debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    vvi to(n);
    rep(i,m){
        int a,b; cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    int k; cin >> k;
    vi c(k);
    rep(i,k){
        cin >> c[i];
        c[i]--;
    }
    vvi dist(k,vi(k));

    auto bfs = [&](int s){
        vi dist(n,INF);
        queue<ll> q;
        dist[s] = 0;
        q.push(s);
        while(!q.empty()){
            int v = q.front(); q.pop();
            for(auto nv : to[v]){
                if(dist[nv]!=INF) continue;
                dist[nv] = dist[v]+1;
                q.push(nv);
            }
        }
        return dist;
    };

    rep(i,k){
        vi d = bfs(c[i]);
        rep(j,k) dist[i][j] = d[c[j]];
    }

    int k2 = 1<<k;
    vector dp(k2,vi(k,INF));
    rep(i,k) dp[1<<i][i] = 1;
    rep(s,k2)rep(i,k){
        if(~s>>i&1) continue;
        rep(j,k){
            if(s>>j&1) continue;
            chmin(dp[s|1<<j][j],dp[s][i]+dist[i][j]);
        }
    }
    ll ans = INF;
    rep(i,k) chmin(ans, dp[k2-1][i]);
    if(ans==INF) ans = -1;
    cout << ans << endl;
}