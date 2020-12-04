#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;

int main(){
  int k,t;
  cin >> k >> t;
  vi a(t);
  rep(i,t) cin >> a[i];
  sort(a.begin(), a.end());
  vi aa(t+1);
  rep(i,t) aa[i+1]=a[i]+aa[i];
  int ans=10000;
  rep(i,t){
    if(aa[i]>aa[t]-aa[i]) ans=0;
    else ans=min(ans, aa[t]-aa[i]*2-1);
  }
  cout << ans << endl;
}