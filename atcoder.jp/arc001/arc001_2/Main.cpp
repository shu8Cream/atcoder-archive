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
  int ans=0;
  int c=abs(a-b);
  ans+=c/10;
  vi d = {0, 1, 2, 3, 2, 1, 2, 3, 3, 2};
  cout << ans + d[c%10] << endl;
}