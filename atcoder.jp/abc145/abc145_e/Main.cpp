/**
*    author:  shu8Cream
*    created: 09.08.2021 21:45:27
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

ll dp[3030][6060];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,t; cin >> n >> t;
    vector<P> ab(n);
    rep(i,n) cin >> ab[i].first >> ab[i].second;
    sort(all(ab));
    rep(i,n)rep(j,3010){
        if(j<t) chmax(dp[i+1][j+ab[i].first], dp[i][j]+ab[i].second);
        chmax(dp[i+1][j],dp[i][j]);
    }
    ll ans = 0;
    rep(i,n+1)rep(j,6060) chmax(ans,dp[i][j]);
    cout << ans << endl;
}