#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
//using mint = modint998244353;
using mint = modint1000000007;

int main(){
  int n, m;
  cin >> n >> m;
  vi a(m);
  rep(i,m) cin >> a[i];
  vector<mint> dp(n+1, 1);
  dp[0]=0;
  dp[1]=1;
  dp[2]=2;
  rep(i,m) dp[a[i]]=0;
  if(dp[1]==0 && dp[2]==2) dp[2]=1;
  rep(i,n-2){
    if(dp[i+3]==0) continue;
    dp[i+3]=dp[i+1]+dp[i+2];
  }
  cout << dp[n].val() << endl;
}