#include <bits/stdc++.h>
#define rep(i,n) for (ll i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  ll a,b,c;
  cin >> a >> b >> c;
  if(a==b && b==c) cout << "No" << endl;
  else if(a==b || b==c || a==c) cout << "Yes" << endl;
  else cout << "No" << endl;
}