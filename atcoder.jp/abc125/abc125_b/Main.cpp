#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
//using mint = modint998244353;
using mint = modint1000000007;

int main(){
  int n;
  cin >> n;
  vi v(n), c(n);
  rep(i,n) cin >> v[i];
  rep(i,n) cin >> c[i];
  int ans=0;
  rep(i,n){
    if(v[i]>c[i]) ans+=v[i]-c[i]; 
  }
  cout << ans << endl;
}