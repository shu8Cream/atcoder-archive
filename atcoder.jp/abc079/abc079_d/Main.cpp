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
  int h,w;
  cin >> h >> w;
  vvi c(10, vi(10));
  rep(i,10)rep(j,10) cin >> c[i][j];
  vvi a(h, vi(w));
  rep(i,h)rep(j,w) cin >> a[i][j];
  for(int k=0;k<10;k++){
    for(int i=0;i<10;i++){
      for(int j=0;j<10;j++) c[i][j]=min(c[i][j],c[i][k]+c[k][j]);
    }
  }
  int ans=0;
  rep(i,h)rep(j,w){
    if(a[i][j]==-1) continue;
    if(a[i][j]!=1) ans+=c[a[i][j]][1];
  }
  cout << ans << endl;
}