#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;

int main(){
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  sort(a.begin(), a.end());
  ll ans=a[n-1], sa=a[n-1];
  ll t = (a[n-1]+1)/2;
  rep(i,n-1){
    ll tmp = abs(t-a[i]);
    if(sa>=tmp){
      ans=a[i];
      sa=tmp;
    }
  }
  printf("%lld %lld\n", a[n-1],ans);
}