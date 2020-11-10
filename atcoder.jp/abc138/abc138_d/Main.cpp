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
vi cnt;

void dfs(int v, int p=-1) {
  for(int u : to[v]){
    if(u==p) continue;
    cnt[u]+=cnt[v];
    dfs(u,v);
  }
}

int main(){
  int n,q;
  cin >> n >> q;
  rep(i,n-1){
    int a,b;
    cin >> a >> b;
    a--;b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  cnt.resize(n);
  rep(i,q){
    int p,x;
    cin >> p >> x;
    p--;
    cnt[p]+=x;
  }
  dfs(0);
  rep(i,n) cout << cnt[i] << endl;
}