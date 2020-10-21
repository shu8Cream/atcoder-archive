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

int main(){
  int n,a,b;
  cin >> n >> a >> b;
  if(n*a>b) cout << b << endl;
  else cout << n*a << endl;
}