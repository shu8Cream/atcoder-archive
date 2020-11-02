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
using mint = modint1000000007;

int main(){
  int n;
  cin >> n;
  vi a(n);
  rep(i,n) cin >> a[i];
  ll x=0, sum=0, ans=1e12;
  rep(i,n) sum+=a[i];
  rep(i,n-1){
    x+=a[i];
    ans=min(ans, abs(sum-2*x));
  }
  cout << ans << endl;
}