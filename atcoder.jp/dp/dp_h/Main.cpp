/**
*    author:  shu8Cream
*    created: 06.01.2021 00:16:21
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

const int mod = 1e9+7;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int h,w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i,h) cin >> a[i];
    vvi dp(h+1, vi(w+1));
    dp[1][1]=1;
    rep(i,h)rep(j,w){
        if(i==0 && j==0) continue;
        if(a[i][j]=='#') dp[i+1][j+1]=0;
        else dp[i+1][j+1]=(dp[i][j+1]+dp[i+1][j])%mod;
    }
    cout << dp[h][w] << endl;
}