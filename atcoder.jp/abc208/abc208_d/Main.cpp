/**
*    author:  shu8Cream
*    created: 16.08.2021 14:49:29
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=(n-1); i>=0; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

template<class T> inline bool chmax(T& a, T b) {
    if (a < b) { a = b; return true; }
    return false;
}
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) { a = b; return true; }
    return false;
}

const ll INF = 1001001001;
ll dp[404][404];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,m;
    cin >> n >> m;
    rep(i,n)rep(j,n){
        if(i!=j) dp[i][j] = INF;
    }

    rep(i,m){
        ll a,b,c; cin >> a >> b >> c;
        dp[a-1][b-1]=c;
    }
    ll ans = 0;
    rep(k,n){
        rep(i,n)rep(j,n) chmin(dp[i][j], dp[i][k]+dp[k][j]);
        rep(i,n)rep(j,n) if(dp[i][j]!=INF) ans += dp[i][j];
    }
    cout << ans << endl;
}