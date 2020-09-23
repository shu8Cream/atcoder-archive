#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  ll n,a,b;
  cin >> n >> a >> b;
  ll ans = n/(a+b)*a;
  ll rem = n%(a+b);
  ans += min(a,rem);
  cout << ans << endl;
}