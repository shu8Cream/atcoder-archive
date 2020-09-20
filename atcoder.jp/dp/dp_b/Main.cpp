#include <bits/stdc++.h>
#define rep(i,n) for (ll i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define INF 1050000000

int main(){
  int n,k;
  cin >> n >> k;
  vector<int> h(n);
  rep(i,n) cin >> h[i];
  vector<int> dp(n, INF);
  dp[0]=0;
  for(int i=1; i<n; i++){
    for(int j=1; j<=min(i,k); j++){
      dp[i] = min(dp[i], dp[i-j]+abs(h[i-j]-h[i]));
    }
  }
  cout << dp[n-1] << endl;
}