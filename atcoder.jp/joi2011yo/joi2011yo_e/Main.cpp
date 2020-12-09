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
  int h,w,n;
  cin >> h >> w >> n;
  vector<string> to(h);
  rep(i,h) cin >> to[i];
  int sum=0;
  
  vector<P> chez;
  rep(k,n+1){
    rep(i,h)rep(j,w){
      if(k==0 && to[i][j]=='S') chez.push_back({i,j});
      else if(to[i][j]==k+'0') chez.push_back({i,j});
    }
  }
  
  rep(j,n){
    vvi dist(h,vi(w,-1));
    dist[chez[j].first][chez[j].second]=0;
    queue<P> que;
    que.push(chez[j]);

    while(!que.empty()){
      int y = que.front().first;
      int x = que.front().second;
      que.pop();

      rep(i,4){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx<0 || nx>=w || ny<0 || ny>=h) continue;
        if(to[ny][nx]=='X') continue;
        if(dist[ny][nx]!=-1) continue;
        dist[ny][nx]=dist[y][x]+1;
        que.push({ny,nx});
      }
    }
    sum+=dist[chez[j+1].first][chez[j+1].second];
  }
  cout << sum << endl;
}