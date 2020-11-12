#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  
  if(b/a<c) cout << b/a << endl;
  else cout << c << endl;
}