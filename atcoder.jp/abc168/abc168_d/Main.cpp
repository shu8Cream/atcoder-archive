#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

vi to[200005];

int main(){
  int n,m;
  cin >> n >> m;
  rep(i,m){
    int a,b;
    cin >> a >> b;
    --a;--b;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  vi dist(n, -1);
  queue<int> q;
  vi pre(n, -1);
  
  dist[0]=0;
  q.push(0);
  
  while(!q.empty()){
    int v = q.front();
    q.pop();
    for(int nv : to[v]){
      if(dist[nv]!=-1) continue;
      dist[nv]=dist[v]+1;
      pre[nv]=v;
      q.push(nv);
    }
  }
  cout << "Yes" << endl;
  rep(i,n){
    if(i==0) continue;
    int ans=pre[i];
    ++ans;
    cout << ans << endl;
  }
}