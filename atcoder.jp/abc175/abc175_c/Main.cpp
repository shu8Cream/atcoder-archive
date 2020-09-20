#include <bits/stdc++.h>
#define rep(i,n) for (ll i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  ll x,k,d;
  cin >> x >> k >> d;
  x=abs(x);
  if(x/d>=k){
    cout << x-k*d << endl;
    return 0;
  }
  if((k-(x/d))%2 == 0) cout << x%d << endl;
  else cout << abs(d-x%d) << endl;
}