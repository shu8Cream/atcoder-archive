#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  int ans=0,cnt=0;
  rep(i,32){
    rep(j,n){
      if(a[j]%2==0){
        cnt++;
        a[j]/=2;
      }
    }
    if(cnt==n) ans++;
    cnt=0;
  }
  cout << ans << endl;
}