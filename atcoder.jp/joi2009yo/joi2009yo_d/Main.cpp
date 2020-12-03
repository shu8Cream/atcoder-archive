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

int w,h,cnt=0;
vvi c;

const vi dx = {-1 ,0, 1, 0};
const vi dy = {0, 1, 0, -1};

int dfs(int x, int y, int cst){
  c[x][y]=0;
  cst++;
  int res=0;
  rep(i,4){
    int nx=x+dx[i], ny=y+dy[i];
    if(nx<0 || nx>=h || ny<0 || ny>=w) continue;
    if(c[nx][ny]==0) continue;
    res=max(res, dfs(nx,ny,cst));
  }
  c[x][y]=1;
  res=max(res, cst);
  return res;
}

int main(){
  cin >> w >> h;
  c.assign(h, vi(w,0));
  vvi cc(h,vi(w));
  rep(i,h)rep(j,w){
    cin >> c[i][j];
    cc[i][j]=c[i][j];
  }
  int ans=0;
  rep(i,h)rep(j,w){
    rep(k,h)rep(l,w) c[k][l]=cc[k][l];
    if(c[i][j]==0) continue;
    ans=max(ans, dfs(i,j,0));
  }
  cout << ans << endl;
}