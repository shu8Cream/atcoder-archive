#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  string s,t,u;
  cin >> s >> t;
  int a,b;
  cin >> a >> b; 
  cin >> u;
  if(s==u) cout << a-1 << " " << b << endl;
  else cout << a << " " << b-1 << endl;
}