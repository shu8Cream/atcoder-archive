#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;

int main(){
  ll n,a,b;
  cin >> n >> a >> b;
  ll ans=1e18;
  if(a%2==b%2) ans=(b-a)/2;
  else ans=min(a-1,n-b)+1+(b-a-1)/2;
  cout << ans << endl;
}