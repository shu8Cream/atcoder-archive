#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using namespace atcoder;

int main(){
  ll a,b,c,d;
  cin >> a >> b >> c >> d;
  if((a<=c&&c<=b) || (a<=d&&d<=b)) cout << "Yes" << endl;
  else if((c<=a&&a<=d) || (c<=b&&b<=d)) cout << "Yes" << endl;
  else cout << "No" <<  endl;
}