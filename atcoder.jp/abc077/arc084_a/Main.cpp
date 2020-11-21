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
  int n;
  cin >> n;
  vector<ll> a(n),b(n),c(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];
  rep(i,n) cin >> c[i];
  ll ans=0;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());
  rep(i,n){
    ll pre = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
    ll over = c.end() - upper_bound(c.begin(), c.end(), b[i]);
    ans+=pre*over;
  }
  cout << ans << endl;
}