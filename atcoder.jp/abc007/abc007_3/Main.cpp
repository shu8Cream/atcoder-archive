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

const vi dx = {1, 0, -1, 0};
const vi dy = {0, 1, 0, -1};

int main(){
  int r,c, sy,sx, gy,gx;
  cin >> r >> c >> sy >> sx >> gy >> gx;
  sy--; sx--; gy--; gx--;
  vector<string> to(r);
  rep(i,r) cin >> to[i];
  vvi dist(r,vi(c,-1));
  dist[sy][sx]=0;
  queue<P> que;
  que.push({sy,sx});
  
  while(!que.empty()){
    int y = que.front().first;
    int x = que.front().second;
    que.pop();
    
    rep(i,4){
      int nx = x+dx[i];
      int ny = y+dy[i];
      if(nx<0 || nx>=c || ny<0 || ny>=r) continue;
      if(to[ny][nx]=='#') continue;
      if(dist[ny][nx]!=-1) continue;
      dist[ny][nx]=dist[y][x]+1;
      que.push({ny,nx});
    }
  }
  cout << dist[gy][gx] << endl;
}