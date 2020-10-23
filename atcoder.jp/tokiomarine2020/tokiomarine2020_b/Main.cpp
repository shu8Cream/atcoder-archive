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
//using mint = modint1000000007;

int main(){
  ll a,v,b,w,t;
  cin >> a >> v >> b >> w >> t;
  if(v-w>0 && abs(b-a)<=t*(v-w) || a==b) cout << "YES" << endl;
  else cout << "NO" << endl;
}