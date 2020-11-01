#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using mint = modint998244353;
//using mint = modint1000000007;

int main(){
  int n;
  cin >> n;
  ll ans=0;
  vector<ll> c(1000005);
  for(int i=1; i<1000005; i++){
    c[i]=c[i-1]+i;
  }
  rep(i,n){
    int a,b;
    cin >> a >> b;
    ans+=c[b]-c[a-1];
  }
  cout << ans << endl;
}