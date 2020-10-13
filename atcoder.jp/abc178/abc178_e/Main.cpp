#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  ll x, y, mxt=-2e9, mnt=2e9, mxu=-2e9, mnu=2e9;
  rep(i,n){
    cin >> x >> y;
    mxt=max(mxt, x+y);
    mnt=min(mnt, x+y);
    mxu=max(mxu, x-y);
    mnu=min(mnu, x-y);
  }
  cout << max(mxt-mnt, mxu-mnu) << endl;
}