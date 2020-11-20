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

int main(){
  int n,k;
  cin >> n >> k;
  vector<ll> h(n);
  rep(i,n) cin >> h[i];
  sort(h.begin(), h.end());
  ll ans=1010101010;
  rep(i,n-k+1){
    ans=min(ans, h[i+k-1]-h[i]);
  }
  cout << ans << endl;
}