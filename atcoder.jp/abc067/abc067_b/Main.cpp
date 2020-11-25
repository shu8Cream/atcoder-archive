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
  vi l(n);
  rep(i,n) cin >> l[i];
  sort(l.rbegin(), l.rend());
  int ans=0;
  rep(i,k) ans+=l[i];
  cout << ans << endl;
} 