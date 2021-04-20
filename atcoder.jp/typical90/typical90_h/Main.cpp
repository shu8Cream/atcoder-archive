/**
*    author:  shu8Cream
*    created: 07.04.2021 23:45:10
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
const string key = "atcoder";

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; string s;
    cin >> n >> s;
    vvi dp(n+5,vi(8));
    dp[0][0]=1;
    rep(i,n){
        rep(j,8){
            dp[i+1][j]+=dp[i][j];
            if(s[i]=='a' && j==0) dp[i+1][j+1]+=dp[i][j];
            if(s[i]=='t' && j==1) dp[i+1][j+1]+=dp[i][j]; 
            if(s[i]=='c' && j==2) dp[i+1][j+1]+=dp[i][j]; 
            if(s[i]=='o' && j==3) dp[i+1][j+1]+=dp[i][j]; 
            if(s[i]=='d' && j==4) dp[i+1][j+1]+=dp[i][j]; 
            if(s[i]=='e' && j==5) dp[i+1][j+1]+=dp[i][j]; 
            if(s[i]=='r' && j==6) dp[i+1][j+1]+=dp[i][j];
        }
        rep(j,8) dp[i+1][j]%=mod;  
    }
    cout << dp[n][7] << endl;
}