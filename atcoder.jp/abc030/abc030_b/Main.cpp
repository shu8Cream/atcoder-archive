#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n,m;
  cin >> n >> m;
  n%=12;
  double ans = abs(6.0*m-(30.0*n+0.5*m));
  if(ans>180) ans=360-ans;
  cout << ans << endl;
}