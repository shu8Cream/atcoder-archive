#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const ll MX=1e18;

int main(){
  int n;
  cin>>n;
  vector<ll> a(n);
  rep(i,n) cin>>a[i];
  ll ans=1;
  sort(a.begin(),a.end());
  rep(i,n){
    if(a[i]==0){
      cout << 0 << endl;
      return 0;
    }
    if(ans>MX || MX/ans<a[i]){
      cout << -1 << endl;
      return 0;
    }
    ans*=a[i];
  }
  cout << ans << endl;
}
