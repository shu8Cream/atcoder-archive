#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using namespace atcoder;
using ll = long long;

int main(){
  int n;
  cin >> n;
  vector<ll> t(n);
  rep(i,n) cin >> t[i];
  ll ans=1;
  for(int i=0; i<n; i++){
    ans=lcm(ans, t[i]);
  }
  cout << ans << endl;
}