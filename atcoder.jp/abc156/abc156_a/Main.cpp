#include <bits/stdc++.h>
#define rep(i,n) for (ll i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  ll n,r;
  cin >> n >> r;
  if(n>=10) cout << r << endl;
  else cout << r+100*(10-n) << endl;
}