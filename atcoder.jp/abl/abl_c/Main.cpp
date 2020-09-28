#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using namespace atcoder;

int main(){
  ll n,m;
  cin >> n >> m;
  vector<int> a(m);
  vector<int> b(m);
  rep(i,m) cin >> a[i] >> b[i];
  dsu d(n);
  rep(i,m) d.merge(a[i]-1, b[i]-1);
  int ans=0;
  rep(i,n){
    if(!d.same(0,i)){
      ans++;
      d.merge(0,i);
    }
  }
  cout << ans << endl;
}