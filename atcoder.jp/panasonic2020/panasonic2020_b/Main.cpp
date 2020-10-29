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
  ll h, w;
  cin >> h >> w;
  ll ans=0;
  if(h==1 || w==1) ans=1;
  else ans=(h*w+2-1)/2;
  cout << ans << endl;
}