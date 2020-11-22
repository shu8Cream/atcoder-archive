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

vector<pair<ll, ll>> edges[200500];
ll ans[105000];
int n;

void dfs(int now) {
  // v から行ける各頂点 next_v について
  for (auto next_v : edges[now]) {
    int to = next_v.first;
    int lav = next_v.second;
    if (ans[to] != 0) continue; // ラベルは１以上なので０だと未探索
    if(lav != ans[now]){
      ans[to] = lav;
    }else{
      ans[to] = (lav+1)%n;
    }
    dfs(to); // 再帰的に探索
  }
}

int main(){
  int m;
  cin >> n >> m;
  while(m--){
    int u,v,c;
    cin >> u >> v >> c;
    u--; v--;
    edges[u].push_back({v, c});
    edges[v].push_back({u, c});
  }
  ans[0]=1;
  dfs(0);
  rep(i,n) cout << ans[i] << endl;
}