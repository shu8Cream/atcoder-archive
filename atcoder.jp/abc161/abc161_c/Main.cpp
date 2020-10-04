#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  ll n,k;
  cin >> n >> k;
  ll x=n, ans=1e18;
  while(1){
    ll tmp=ans;
    if(x>=k) x=x%k;
    else x=abs(x-k);
    ans=min(ans, x);
    if(tmp==ans) break;
  }
  cout << ans << endl;
}