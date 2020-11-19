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

bool to[20][20];

int main(){
  int n,m;
  cin >> n >> m;
  rep(i,m){
    int x,y;
    cin >> x >> y;
    x--; y--;
    to[x][y] = to[y][x] = true;
  }
  int ans=0;
  rep(s, 1<<n){
    int t = bitset<20>(s).count();
    if(t<=ans) continue;
    bool ok = true;
    rep(i,n)rep(j,i){
      if(s>>i & s>>j & 1 && !to[i][j]) ok = false;
    }
    if(ok) ans=t;
  }
  cout << ans << endl;
}