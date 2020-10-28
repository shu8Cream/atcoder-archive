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
  int n;
  cin >> n;
  vvi ft(n, vi(10));
  rep(i,n)rep(j,10) cin >> ft[i][j];
  vector<bitset<10>> f(n);
  rep(i,n)rep(j,10){
    if(ft[i][j]==1) f[i].set(j);
  }
  vvi p(n, vi(11));
  rep(i,n)rep(j,11) cin >> p[i][j];
  ll ans=-1e9;
  vector<bitset<10>> a(1024);
  for (int tmp = 0; tmp < (1 << 10); tmp++) {
    bitset<10> s(tmp);
    a[tmp]=s;
  }
  for(int i=1; i<1024; i++){
    ll pans=0;
    rep(j,n){
      auto c = a[i] & f[j];
      pans+=p[j][c.count()];
    }
    ans=max(ans, pans);
  }
  cout << ans << endl;
}