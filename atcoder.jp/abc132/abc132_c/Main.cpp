#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
//using mint = modint1000000007;

int main(){
  int n;
  cin >> n;
  vi d(n);
  rep(i,n) cin >> d[i];
  sort(d.begin(), d.end());
  int ans=0;
  ans=d[n/2]-d[n/2-1];
 
  cout << ans << endl;
}