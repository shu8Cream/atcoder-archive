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
  int n,m;
  cin >> n >> m;
  vvi a(n, vi(m));
  rep(i,n)rep(j,m) cin >> a[i][j];
  ll ans=0;
  rep(i,m){
    for(int j=i+1; j<m; j++){
      ll sum=0;
      rep(k,n) sum+=max(a[k][i], a[k][j]);
      ans=max(ans, sum);
    }
  }
  cout << ans << endl;
}