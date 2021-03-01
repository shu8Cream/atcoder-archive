/**
*    author:  shu8Cream
*    created: 13.12.2020 21:53:12
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;

const int INF = 1001001001;

int main() {
    int n,m;
    cin >> n >> m;
    vi a(n), b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    vvi dp(n+1,vi(m+1,INF));
    dp[0][0]=0;
    rep(i,n+1)rep(j,m+1){
        if(i<n) dp[i+1][j]=min(dp[i+1][j], dp[i][j]+1);
        if(j<m) dp[i][j+1]=min(dp[i][j+1], dp[i][j]+1);
        if(i<n && j<m){
            int cst = 0;
            if(a[i]!=b[j]) cst=1;
            dp[i+1][j+1]=min(dp[i+1][j+1], dp[i][j]+cst);
        }
    }
    cout << dp[n][m] << endl;
}