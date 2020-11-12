#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n;
  cin >> n;
  vi p(n);
  rep(i,n) cin >> p[i];
  sort(p.begin(),p.end());
  int ans=0;
  rep(i,n-1) ans+=p[i];
  ans+=p[n-1]/2;
  cout << ans << endl;
}