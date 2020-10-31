#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
//using mint = modint1000000007;

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  if(a<=b && a<=c && c<=b) cout << "Yes" << endl;
  else if(a>=b && b<=c && c<=a) cout << "Yes" << endl;
  else cout << "No" << endl;
}