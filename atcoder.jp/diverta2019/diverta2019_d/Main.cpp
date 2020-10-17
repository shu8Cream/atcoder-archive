#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  ll n;
  cin >> n;
  ll ans=0;
  for(ll k=1; k*k<=n; k++){
    ll m=n/k-1;
    if(m<=0) continue;
    if(n==m*k+k&&n/m==n%m) ans+=m;
  }
  cout << ans << endl;
}