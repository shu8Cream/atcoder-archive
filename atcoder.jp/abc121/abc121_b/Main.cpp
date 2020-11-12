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
  int n,m,c;
  cin >> n >> m >> c;
  vi b(m);
  rep(i,m) cin >> b[i];
  vvi a(n, vi(m));
  rep(i,n)rep(j,m) cin >> a[i][j];
  int ans=0;
  rep(i,n){
    int cnt=c;
    rep(j,m){
      cnt+=a[i][j]*b[j];
    }
    if(cnt>0) ans++;
  }
  cout << ans << endl;
}