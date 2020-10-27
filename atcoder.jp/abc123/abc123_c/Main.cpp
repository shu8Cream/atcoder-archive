#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  ll n;
  cin >> n;
  vector<ll> a(5);
  rep(i,5) cin >> a[i];
  sort(a.begin(), a.end());
  ll ans=4+(n+a[0]-1)/a[0];
  cout << ans << endl;
}