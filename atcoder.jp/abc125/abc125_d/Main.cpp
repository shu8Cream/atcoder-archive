#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n;
  cin >> n;
  vi a(n);
  rep(i,n) cin >> a[i];
  sort(a.begin(), a.end());
  ll ans=0;
  rep(i,n-1){
    if(a[i]<0 && a[i+1]<0) {a[i]*=-1; a[i+1]*=-1;}
    if(a[i]<0 && a[i+1]>=0){
      if(abs(a[i])>a[i+1]) {a[i]*=-1; a[i+1]*=-1;}
    }
  }
  rep(i,n) ans+=a[i];
  cout << ans << endl;
}