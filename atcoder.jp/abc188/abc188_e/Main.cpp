/**
*    author:  shu8Cream
*    created: 11.01.2021 12:17:45
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vi a(n);
    rep(i,n) cin >> a[i];
    vvi to(n);
    rep(i,m){
        int x,y;
        cin >> x >> y;
        x--;y--;
        to[x].push_back(y);
    }
    const int INF = 1001001001;
    vi dp(n,INF*2);
    int ans = -INF;
    rep(i,n){
        ans=max(ans,a[i]-dp[i]);
        for(int j : to[i]){
            dp[j]=min(dp[j],dp[i]);
            dp[j]=min(dp[j],a[i]);
        }
    }
    cout << ans << endl;
}