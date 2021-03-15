/**
*    author:  shu8Cream
*    created: 15.03.2021 18:58:11
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

int dp[55][510][510];
const int INF = 1e9;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,ma,mb;
    cin >> n >> ma >> mb;
    vi a(n),b(n),c(n);
    rep(i,n) cin >> a[i] >> b[i] >> c[i];
    rep(i,55)rep(j,510)rep(k,510) dp[i][j][k]=INF;
    dp[0][0][0]=0;
    rep(i,n)rep(wa,500)rep(wb,500){
        if(dp[i][wa][wb]>=INF) continue;
        dp[i+1][wa][wb]=min(dp[i+1][wa][wb], dp[i][wa][wb]);
        dp[i+1][wa+a[i]][wb+b[i]]=min(dp[i+1][wa+a[i]][wb+b[i]], dp[i][wa][wb]+c[i]);
    }
    int ans = INF;
    for(int wa=1; wa<500; wa++){
        for(int wb=1; wb<500; wb++){
            if(wa*mb!=wb*ma) continue;
            ans = min(ans, dp[n][wa][wb]);
        }
    }
    if(ans!=INF) cout << ans << endl;
    else cout << -1 << endl;
}