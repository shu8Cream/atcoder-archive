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
  int n,k;
  cin >> n >> k;
  vvi t(n, vi(n));
  rep(i,n)rep(j,n) cin >> t[i][j];
  vi c(n-1);
  rep(i,n-1) c[i]=i+1;
  int ans=0,cnt=0;
  do{
    int cst=t[0][c[0]];
    rep(i,n-2){
      cst+=t[c[i]][c[i+1]];
      //cout << c[i] << "," << c[i+1] << " ";
      //cout << cst << endl;
    }
    cst+=t[c[n-2]][0];
    if(cst==k) ans++;
  }while(next_permutation(c.begin(), c.end()));
  cout << ans << endl;
}