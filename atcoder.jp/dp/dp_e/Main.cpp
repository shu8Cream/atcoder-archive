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
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const ll INF = 1LL<<60;
const int MAXV = 100100;
vector<vector<ll>> dp(110, vector<ll>(100100, INF));

int main(){
  ll n,W;
  cin >> n >> W;
  vector<ll> w(n+1),v(n+1);
  rep(i,n) cin >> w[i] >> v[i];
  dp[0][0]=0;
  
  rep(i,n){
    rep(sumv,MAXV){
      if(sumv-v[i]>=0){
      	chmin(dp[i+1][sumv], dp[i][sumv-v[i]]+w[i]);
      }
      chmin(dp[i+1][sumv], dp[i][sumv]);
    }
  }
  ll ans=0;
  rep(sumv, MAXV){
    if(dp[n][sumv]<=W) ans=sumv;
  }
  cout << ans << endl;
}