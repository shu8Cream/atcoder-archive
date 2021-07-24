/**
*    author:  shu8Cream
*    created: 24.07.2021 20:10:59
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

const int mod = 1e9+7;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s; cin >> s;
    int n = s.size();
    vvi dp(n+5,vi(9));
    dp[0][0]=1;
    rep(i,n){
        rep(j,9){
            dp[i+1][j]+=dp[i][j];
            if(s[i]=='c' && j==0) dp[i+1][j+1]+=dp[i][j];
            if(s[i]=='h' && j==1) dp[i+1][j+1]+=dp[i][j]; 
            if(s[i]=='o' && j==2) dp[i+1][j+1]+=dp[i][j]; 
            if(s[i]=='k' && j==3) dp[i+1][j+1]+=dp[i][j]; 
            if(s[i]=='u' && j==4) dp[i+1][j+1]+=dp[i][j]; 
            if(s[i]=='d' && j==5) dp[i+1][j+1]+=dp[i][j]; 
            if(s[i]=='a' && j==6) dp[i+1][j+1]+=dp[i][j];
            if(s[i]=='i' && j==7) dp[i+1][j+1]+=dp[i][j];
        }
        rep(j,9) dp[i+1][j]%=mod;  
    }
    cout << dp[n][8] << endl;
}