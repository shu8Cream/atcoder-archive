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
  ll a,b,c;
  cin >> a >> b >> c;
  if(4*a*b-(c-a-b)*(c-a-b)<0 && c-a-b>0) cout << "Yes" << endl;
  else cout << "No" << endl;
}