#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using mint = modint998244353;
//1000000007;

int main(){
  ll a,b,c;
  cin >> a >> b >> c;
  mint ans=a*(a+1)/2;
  ans*=b*(b+1)/2;
  ans*=c*(c+1)/2;
  cout << ans.val() << endl;
}