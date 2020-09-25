#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  ll n,m,k;
  cin >> n >> m >> k;
  vector<int> a(n);
  vector<int> b(m);
  rep(i,n) cin >> a[i];
  rep(i,m) cin >> b[i];
  ll t=0;
  rep(i,m) t+=b[i];
  int j=m;
  int ans=0;
  rep(i,n+1){
    while(t>k && j>0){
      j--;
      t-=b[j];
    }
    if(t>k) break;
    ans=max(ans, i+j);
    if(i==n) break;
    t+=a[i];
  }
  cout << ans << endl;
}