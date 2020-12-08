#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) { a = b; return true; } 
  return false; 
}
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) { a = b; return true; } 
  return false; 
}

vvi dp(3010, vi(3010,0));

int main(){
  string s,t;
  cin >> s >> t;
  int n = s.size();
  int m = t.size();
  int a=0;
  stack<char> st;
  for(int i=1; i<=n; i++)for(int j=1; j<=m; j++){
    if(s[i-1]==t[j-1]) a=1;
    else a=0;
    dp[i][j]=max({dp[i-1][j-1]+a, dp[i][j-1], dp[i-1][j]});
  }
  int i=n, j=m; 
  string ans="";
  while (i>0 && j>0) {
    // 上に辿る
    if(dp[i][j] == dp[i-1][j])
      i--;
    // 左に辿る
    else if(dp[i][j] == dp[i][j-1])
      j--;
    // 斜めにたどる
    else{
      ans = s[i-1] + ans;
      i--; j--;
    }
  }
  cout << ans << endl;
}