#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int a,b;
  cin >> a >> b;
  if(a>9 || b>9) cout << -1 << endl;
  else cout << a*b << endl;
}