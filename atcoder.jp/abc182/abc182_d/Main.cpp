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
//using mint = modint1000000007;

int main(){
  int n;
  cin >> n;
  vector<ll> a(n), di(n), dim(n);
  rep(i,n){
    cin >> a[i];
    if(i!=0) di[i]+=a[i]+di[i-1];
    else di[i]=a[i];
  }
  rep(i,n){
    if(i==0) dim[i]=di[0];
    else dim[i]=max(dim[i-1], di[i]);
  }
  ll ans=0, sumd=0;
  rep(i,n){
    if(i==0) ans=max(ans, di[0]);
    else ans=max(ans, max(sumd,sumd+dim[i]));
    sumd+=di[i];
  }
  cout << ans << endl;
}