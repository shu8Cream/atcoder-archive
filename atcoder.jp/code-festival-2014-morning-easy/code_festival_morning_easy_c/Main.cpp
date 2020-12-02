#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;

const int INF = 1e9+1;
const int MAX_V = 1010;

struct edge { int to, cost; };

int d[MAX_V];
vector<edge> G[MAX_V];

void dijkstra(int s){
  rep(i,MAX_V) d[i]=INF;
  d[s]=0;
  priority_queue<P, vector<P>, greater<P>> que;
  que.push(P(0,s));
  while(!que.empty()){
    P p = que.top();
    que.pop();
    int v = p.second;
    if(d[v] < p.first) continue;
    for(auto e : G[v]){
      if(d[e.to] > d[v] + e.cost){
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
      }
    }
  }
}

int main(){
  int n,m,s,t;
  cin >> n >> m >> s >> t;
  s--; t--;
  rep(i,m){
    int x,y,D;
    cin >> x >> y >> D;
    x--; y--;
    G[x].push_back({y,D});
    G[y].push_back({x,D});
  }
  rep(i,n){
    dijkstra(s);
    int tmp = d[i];
    dijkstra(i);
    if(tmp==d[t] && tmp!=INF){
      cout << i+1 << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}