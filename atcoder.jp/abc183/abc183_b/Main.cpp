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

int main(){
  double sx,sy,gx,gy;
  cin >> sx >> sy >> gx >> gy;
  sy*=-1;
  double d=(gy-sy)/(gx-sx);
  double ans=sx+abs(sy)/d;
  printf("%.10lf", ans);
}