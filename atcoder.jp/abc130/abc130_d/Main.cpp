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
  ll n,k;
  cin >> n >> k;
  vi a(n);
  rep(i,n) cin >> a[i];
  vector<ll> r(n+1);
  rep(i,n) r[i+1]=r[i]+a[i];
  ll ans=0;
  rep(i,n+1){
    int index = lower_bound(r.begin(), r.end(), k+r[i]) - r.begin();
    ans+=n+1-index;
  }
  cout << ans << endl;
}