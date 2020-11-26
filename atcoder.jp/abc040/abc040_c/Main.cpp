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

ll dp[100100];

int main(){
  int n;
  cin >> n;
  vi a(n);
  rep(i,n) cin >> a[i];
  dp[1]=abs(a[0]-a[1]);
  rep(i,n){
    dp[i+2]=min(dp[i+1]+abs(a[i+1]-a[i+2]), dp[i]+abs(a[i]-a[i+2]));
  }
  cout << dp[n-1] << endl;
}