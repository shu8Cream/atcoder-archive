/**
*    author:  shu8Cream
*    created: 15.05.2021 20:32:57
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

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int h,w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i,h) cin >> a[i];
    vvi s(h,vi(w));
    rep(i,h)rep(j,w){
        if(a[i][j]=='+') s[i][j]=1;
        else s[i][j]=-1;
    }
    vvi dp(h,vi(w));
    rrep(i,h)rrep(j,w){
        if(i==h-1 && j==w-1) continue;
        dp[i][j] = -8e18;
        if(i+1<h) chmax(dp[i][j], s[i+1][j] - dp[i+1][j]);
        if(j+1<w) chmax(dp[i][j], s[i][j+1] - dp[i][j+1]);
    }
    cout << (dp[0][0]>0 ? "Takahashi" : (dp[0][0]!=0 ? "Aoki" : "Draw")) << endl;
}