/**
*    author:  shu8Cream
*    created: 18.09.2021 20:48:22
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

template<class T> inline bool chmax(T& a, T b) {
    if (a < b) { a = b; return true; }
    return false;
}
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) { a = b; return true; }
    return false;
}

ll dp[330][330][330];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,x,y; cin >> n >> x >> y;
    vector<P> xy(n);
    int sumx = 0, sumy = 0;
    rep(i,n){
        int a,b; cin >> a >> b;
        xy[i] = {a,b};
        sumx += a;
        sumy += b;
    }
    if(sumx<x || sumy<y){
        cout << -1 << endl;
        return 0;
    }
    rep(i,330)rep(j,330)rep(k,330) dp[i][j][k]=-1;
    dp[0][0][0] = 0;
    rep(i,n)rep(j,301)rep(k,301){
        if(dp[i][j][k]==-1) continue;
        if(dp[i+1][min(int(j+xy[i].first),300)][min(int(k+xy[i].second),300)]!=-1) chmin(dp[i+1][min(int(j+xy[i].first),300)][min(int(k+xy[i].second),300)], dp[i][j][k] + 1);
        else dp[i+1][min(int(j+xy[i].first),300)][min(int(k+xy[i].second),300)] = dp[i][j][k] + 1;
        if(dp[i+1][j][k]!=-1) chmin(dp[i+1][j][k], dp[i][j][k]); 
        else dp[i+1][j][k] = dp[i][j][k];
    }
    ll ans = 1000;
    rep(i,301)rep(j,301){
        if(dp[n][i][j]==-1) continue;
        // cout << i << " " << j << " " << dp[n][i][j] << endl;
        if(i>=x && j>=y) chmin(ans, dp[n][i][j]);
    }
    cout << ans << endl;
}