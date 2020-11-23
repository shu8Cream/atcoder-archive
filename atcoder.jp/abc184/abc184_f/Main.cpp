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
  ll n,T;
  cin >> n >> T;
  vi a(n);
  rep(i,n) cin >> a[i];
  vector<ll> s,t;
  s = t = {0};
  rep(i,n){
    for(int j=s.size()-1; j>=0; j--){
      s.push_back(s[j]+a[i]);
    }
    swap(s,t);
  }
  sort(s.begin(), s.end());
  ll ans = 0;
  for(ll x : t){
    if(x>T) continue;
    int si = upper_bound(s.begin(), s.end(), T-x) - s.begin();
    ans = max(ans, x+s[si-1]);
  }
  cout << ans << endl; 
}