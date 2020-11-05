#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
//using mint = modint998244353;
using mint = modint1000000007;

int main(){
  ll n,m;
  cin >> n >> m;
  vi l(m),r(m);
  rep(i,m) cin >> l[i] >> r[i];
  sort(l.begin(), l.end());
  sort(r.begin(), r.end());
  int ans=r[0]-l[m-1]+1;
  if(ans>0) cout << ans << endl;
  else cout << 0 << endl;
}