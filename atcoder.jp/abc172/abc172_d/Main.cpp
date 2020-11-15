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
  vi a(n+1);
  for(int i=1; i<=n; i++){
    for(int j=i; j<=n; j+=i) a[j]++;
  }
  ll ans=0;
  for(int i=1; i<=n; i++){
    ans+=(ll)i*a[i];
  }
  cout << ans << endl;
}