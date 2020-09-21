#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  a=max(a,c);
  b=min(b,d);
  if(b-a>0) cout << b-a << endl;
  else cout << 0 << endl;
}