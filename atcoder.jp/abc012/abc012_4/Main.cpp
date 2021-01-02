/**
*    author:  shu8Cream
*    created: 02.01.2021 11:09:33
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

const int INF = 100100100;

int main() {
    int n,m;
    cin >> n >> m;
    vvi dp(n, vi(n, INF));
    rep(i,m){
        int a,b,t;
        cin >> a >> b >> t;
        a--;b--;
        dp[a][b]=t;
        dp[b][a]=t;
    }
    rep(k,n)rep(i,n)rep(j,n) dp[i][j]=min(dp[i][j], dp[i][k]+dp[k][j]);
    int ans = INF;
    rep(i,n){
        int tmp=0;
        rep(j,n){
            if(i==j) continue;
            tmp=max(tmp,dp[i][j]);
        }
        ans=min(ans,tmp);
    }
    cout << ans << endl;
}