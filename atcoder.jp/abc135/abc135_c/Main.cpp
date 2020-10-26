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
  int n;
  cin >> n;
  vi a(n+1), b(n);
  rep(i,n+1) cin >> a[i];
  rep(i,n) cin >> b[i];
  ll ans=0;
  rep(i,n){
    if(a[i]+a[i+1]>=b[i]){
      ans+=b[i];
      if(b[i]>a[i]) a[i+1]-=b[i]-a[i];
    }else{
      ans+=a[i]+a[i+1];
      a[i+1]=0;
    }
  }
  cout << ans << endl;
}