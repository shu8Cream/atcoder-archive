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
  int a,b;
  cin >> a >> b;
  if((a+b)/2==(double)(a+b)/2) cout << (a+b)/2 << endl;
  else cout << "IMPOSSIBLE" << endl;
}