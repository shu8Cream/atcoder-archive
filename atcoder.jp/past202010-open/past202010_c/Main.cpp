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

vi dx = {1, 0, -1, 0, 1, 1, -1, -1};
vi dy = {0, 1, 0, -1, 1, -1, -1, 1};

int main(){
  int n,m;
  cin >> n >> m;
  vector<string> s(n);
  rep(i,n) cin >> s[i];
  rep(i,n){
    rep(j,m){
      int cnt=0;
      if(s[i][j]=='#') cnt++;
      rep(k,8){
        if(i+dx[k]<0 || i+dx[k]>=n) continue;
        if(j+dy[k]<0 || j+dy[k]>=m) continue;
        if(s[i+dx[k]][j+dy[k]]=='#') cnt++;
      }
      cout << cnt;
    }
    cout << endl;
  }
} 