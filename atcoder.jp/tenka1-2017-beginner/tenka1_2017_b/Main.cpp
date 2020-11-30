#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;

int main(){
  int n;
  cin >> n;
  vector<P> ab(n);
  rep(i,n) cin >> ab[i].first >> ab[i].second;
  sort(ab.rbegin(), ab.rend());
  ll ans = ab[0].first + ab[0].second;
  cout << ans << endl;
}