#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  ll a,b,x;
  cin >> a >> b >> x;
  ll ans=0;
  if(a==0) ans=b/x+1;
  else ans=b/x-(a-1)/x;
  cout << ans << endl;
}