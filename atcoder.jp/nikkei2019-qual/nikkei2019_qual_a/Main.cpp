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
  int n,a,b;
  cin >> n >> a >> b;
  if(a<=b && n-a-b>=0) cout << a << " " << 0 << endl;
  else if(a>b && n-a-b>=0) cout << b << " " << 0 << endl;
  else if(a<=b && n-a-b<0) cout << a << " " << a+b-n << endl;
  else if(a>b && n-a-b<0) cout << b << " " << a+b-n << endl;
}