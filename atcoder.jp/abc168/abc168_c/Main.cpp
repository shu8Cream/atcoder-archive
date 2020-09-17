#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<double, double>;

int main(){
  int a,b,h,m;
  cin >> a >> b >> h >> m;
  P ss(a*sin(h*M_PI/6+m*M_PI/360), -a*cos(h*M_PI/6+m*M_PI/360));
  P ls(b*sin(m*M_PI/30), -b*cos(m*M_PI/30));
  double dx=ss.first-ls.first;
  double dy=ss.second-ls.second;
  double ans = sqrt(dx*dx+dy*dy);
  printf("%.10lf\n", ans);
}