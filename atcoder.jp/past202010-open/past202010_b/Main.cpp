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
  int x,y;
  cin >> x >> y;
  int z=x*100/y;
  if(y==0) cout << "ERROR" << endl;
  else printf("%.02f", (double)z/100);
} 