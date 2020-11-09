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
  int a,b;
  cin >> a >> b;
  if(a-b>1) cout << 2*a-1 << endl;
  else if(b-a>1) cout << 2*b-1 << endl;
  else cout << a+b << endl;
}