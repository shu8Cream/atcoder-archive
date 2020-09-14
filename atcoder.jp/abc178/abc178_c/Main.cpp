#include <bits/stdc++.h>
#define rep(i,n) for (ll i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const ll mod=1000000007;

int powmod(ll x, ll y){
    ll ans=1;
    rep(i,y){
        ans=ans*x%mod;
    }
    return ans;
}

int main(){
  int n;
  cin >> n;
  ll ans=powmod(10,n)-powmod(9,n)-powmod(9,n)+powmod(8,n);
  ans%=mod;
  ans=(ans+mod)%mod;
  cout << ans << endl;
}