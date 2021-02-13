/**
*    author:  shu8Cream
*    created: 13.02.2021 11:13:03
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
    int n;
    cin >> n;
    vi a(n);
    rep(i,n) cin >> a[i];
    vector<vector<ll>> dp(n, vector<ll>(21));
    dp[0][a[0]]=1;
    rep(i,n-1){
        rep(j,21){
            if(j+a[i+1]<21) dp[i+1][j]+=dp[i][j+a[i+1]];
            if(j-a[i+1]>-1) dp[i+1][j]+=dp[i][j-a[i+1]];
        }
    }
    cout << dp[n-2][a[n-1]] << endl;
}