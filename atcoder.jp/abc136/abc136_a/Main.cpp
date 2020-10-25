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
  int a,b,c;
  cin >> a >> b >> c;
  if(c-a+b>0) cout << c-(a-b) << endl;
  else cout << 0 << endl;
}