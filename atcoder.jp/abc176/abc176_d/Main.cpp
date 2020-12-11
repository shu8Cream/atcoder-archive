#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;

const vi dx = {1, 0, -1, 0};
const vi dy = {0, 1, 0, -1};

int main(){
  int h,w,sh,sw,gh,gw;
  cin >> h >> w >> sh >> sw >> gh >> gw;
  sh--; sw--; gh--; gw--;
  vector<string> to(h);
  rep(i,h) cin >> to[i];
  int wp=0;
  const int INF = 1e9;
  vvi dist(h,vi(w,INF));
  dist[sh][sw]=0;
  deque<P> que;
  que.push_back({sh,sw});

  while(!que.empty()){
    int y = que.front().first;
    int x = que.front().second;
    que.pop_front();
    rep(i,4){
      int nx = x+dx[i];
      int ny = y+dy[i];
      if(nx<0 || nx>=w || ny<0 || ny>=h) continue;
      if(to[ny][nx]=='#') continue;
      if(dist[ny][nx]<=dist[y][x]) continue;
      dist[ny][nx]=dist[y][x];
      que.push_front({ny,nx});
    }
    //warp
    for(int wi=-2; wi<=2; wi++){
      for(int wj=-2; wj<=2; wj++){
        int nx = x+wi;
        int ny = y+wj;
        if(nx<0 || nx>=w || ny<0 || ny>=h) continue;
        if(to[ny][nx]=='#') continue;
        if(dist[ny][nx]<=dist[y][x]) continue;
        dist[ny][nx]=dist[y][x]+1;
        que.push_back({ny,nx});
      }
    }
  }
  if(dist[gh][gw]==INF) cout << -1 << endl;
  else cout << dist[gh][gw] << endl;
}
