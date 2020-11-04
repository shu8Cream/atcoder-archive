#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
//using mint = modint998244353;
using mint = modint1000000007;

int main(){
  int a,b;
  cin >> a >> b;
  if(a>=13) cout << b << endl;
  else if(6<=a && a <=12) cout << b/2 <<endl;
  else cout << 0 << endl;
}