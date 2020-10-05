#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  ll a,b,n;
  cin >> a >> b >> n;
  ll ans=0;
  if(b>n) ans=a*n/b;
  else ans=a*(2*b-1)/b-a;
  cout << ans << endl;
}