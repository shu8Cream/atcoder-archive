#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n,m;
  cin >> n >> m;
  ll ans=0;
  if(n==1 && m==1) ans=1;
  else if(n==1) ans=m-2;
  else if(m==1) ans=n-2;
  else if(n==2 || m==2) ans=0;
  else ans=ll(n-2)*(m-2);
  cout << ans << endl;
}