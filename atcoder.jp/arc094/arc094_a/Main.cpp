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
  vi a(3);
  rep(i,3) cin >> a[i];
  int ans=0;
  sort(a.begin(), a.end());
  ans=a[2]-a[1];
  a[0]+=ans;
  if((a[2]-a[0])%2==0) ans+=(a[2]-a[0])/2;
  else ans+=(a[2]-a[0]+1)/2+1;
  cout << ans << endl;
}