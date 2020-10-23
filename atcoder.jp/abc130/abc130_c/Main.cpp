#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int w,h,x,y;
  cin >> w >> h >> x >> y;
  double minMaxArea=(double)w*h/2;
  int multi=0;
  if(w==x*2 && h==y*2) multi=1;
  printf("%.10lf ", minMaxArea);
  cout << multi << endl;
}