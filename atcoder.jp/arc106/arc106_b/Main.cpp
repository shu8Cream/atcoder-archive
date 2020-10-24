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
  vi a(n), b(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];
  dsu u(n);
  rep(i,m){
    int c,d;
    cin >> c >> d;
    u.merge(c-1, d-1);
  }
  int cnt=1;
  vvi g = u.groups();
  int k=g.size();
  rep(i,k){
    ll asum=0, bsum=0;
    rep(j,g[i].size()){
      int tmp=g[i][j];
      asum+=a[tmp];
      bsum+=b[tmp];
    }
    if(asum!=bsum) cnt=0;
  }
  if(cnt) cout << "Yes" << endl;
  else cout << "No" << endl;
}