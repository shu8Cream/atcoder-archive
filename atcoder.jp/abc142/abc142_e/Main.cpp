/**
*    author:  shu8Cream
*    created: 06.11.2021 21:44:09
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

ll dp[1010][1<<12];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    vi a(m),b(m);
    vi c(m);
    rep(i,m){
        cin >> a[i] >> b[i];
        rep(j,b[i]){
            int cc; cin >> cc; cc--;
            c[i] += (1<<cc);
        }
    }
    rep(i,1010)rep(j,1<<12) dp[i][j] = INF;
    dp[0][0] = 0;

    rep(i,m){
        rep(j,1<<n){
            chmin(dp[i+1][j],dp[i][j]);
            chmin(dp[i+1][j|c[i]], dp[i][j] + a[i]);
        }
    }
    if(dp[m][(1<<n)-1]==INF) cout << -1 << endl;
    else cout << dp[m][(1<<n)-1] << endl;
}