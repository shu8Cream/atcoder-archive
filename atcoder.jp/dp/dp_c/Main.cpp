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

ll dp[100100][3];

int main(){
  int n;
  cin >> n;
  ll a[100100][3];
  rep(i,n)rep(j,3) cin >> a[i][j];
  rep(i,n){
    rep(j,3){
      rep(k,3){
        if(j==k) continue;
        chmax(dp[i+1][k], dp[i][j]+a[i][k]);
      }
    }
  }
  ll res = 0;
  rep(i,3) chmax(res, dp[n][i]);
  cout << res << endl;
}