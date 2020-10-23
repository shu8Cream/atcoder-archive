#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
//using mint = modint998244353;
//using mint = modint1000000007;

int main(){
  int n,x;
  cin >> n >> x;
  vi l(n), d(n+1);
  rep(i,n) cin >> l[i];
  int ans=0;
  d[0]=0;
  rep(i,n) d[i+1]=d[i]+l[i];
  rep(i,n+1) if(d[i]<=x) ans++;
  cout << ans << endl;
}