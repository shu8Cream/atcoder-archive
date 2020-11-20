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
  vector<ll> a(n),b(n);
  rep(i,n) cin >> a[i] >> b[i];
  ll ans=0;
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  rep(i,n){
    a[i]+=ans;
    if(a[i]%b[i]==0) continue;
    ans+=b[i]-a[i]%b[i];
  }
  cout << ans << endl;
}