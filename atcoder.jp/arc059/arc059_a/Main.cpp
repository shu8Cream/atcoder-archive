#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  int ans=1e7;
  for(int j=-100; j<101; j++){
    int cst=0;
  	rep(i,n){
      cst+=abs(a[i]-j)*abs(a[i]-j);
    }
    ans=min(cst, ans);
  }
  cout << ans << endl;
}