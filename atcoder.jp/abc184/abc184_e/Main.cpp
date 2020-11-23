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

const int INF = 100100100;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main(){
  int h,w;
  cin >> h >> w;
  vector<string> field(h);
  rep(i,h) cin >> field[i];
  vvi dist(h, vi(w, INF));
  
  queue<P> q;
  rep(i,h)rep(j,w){
    if(field[i][j]=='S'){
      q.emplace(i,j);
      dist[i][j]=0;
    }
  }
  
  vector<vector<P>> warps(256);
  rep(i,h)rep(j,w) warps[field[i][j]].emplace_back(i,j);
  
  while(!q.empty()){
    auto [i,j] = q.front(); q.pop();
    if(field[i][j]=='G'){
      cout << dist[i][j] << endl;
      return 0;
    }
    rep(v,4){
      int ni = i+dx[v], nj = j+dy[v];
      if(ni<0 || ni>=h || nj<0 || nj>=w) continue;
      if(field[ni][nj]=='#') continue;
      if(dist[ni][nj]!=INF) continue;
      dist[ni][nj] = dist[i][j]+1;
      q.emplace(ni,nj);
    }
  	
    if(islower(field[i][j])){
      for(P p : warps[field[i][j]]){
        int ni = p.first, nj = p.second;
        if(dist[ni][nj]!=INF) continue;
        dist[ni][nj] = dist[i][j]+1;
        q.emplace(ni,nj);
      }
      warps[field[i][j]] = vector<P>();
    }
  }
  cout << -1 << endl;
}