#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n-1);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];
  rep(i,n-1) cin >> c[i];
  int ans=0;
  rep(i,n){
    ans+=b[a[i]-1];
    if(i && a[i]-1==a[i-1]) ans+=c[a[i-1]-1];
  }
  cout << ans << endl;
}