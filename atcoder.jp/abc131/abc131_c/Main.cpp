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
  ll a,b,c,d;
  cin >> a >> b >> c >> d;
  a--;
  ll e=c*d/__gcd(c,d);
  ll ai=a-a/c-a/d+a/e;
  ll bi=b-b/c-b/d+b/e;
  cout << bi-ai << endl;
}