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

ll dp[110][100100];

int main(){
  ll n,W;
  cin >> n >> W;
  vector<ll> w(n+1),v(n+1);
  rep(i,n) cin >> w[i] >> v[i];
  rep(i,n){
    rep(sumw,W+1){
      if(sumw-w[i]>=0){
      	dp[i+1][sumw]=max(dp[i+1][sumw], dp[i][sumw-w[i]]+v[i]);
      }
      dp[i+1][sumw]=max(dp[i+1][sumw], dp[i][sumw]);
    }
  }
  cout << dp[n][W] << endl;
}