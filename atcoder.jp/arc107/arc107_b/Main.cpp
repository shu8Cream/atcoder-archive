#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using mint = modint998244353;

int main(){
  int n,k;
  cin >> n >> k;
  ll ans=0;
  for(int x=2; x<=2*n; x++){
    if(x-k<2 || 2*n<x-k) continue;
    if(x-k<-2*(n-1)+x || 2*(n-1)+x<x-k) continue;
    int y=x-k;
    ll xi=0,yi=0;
    if((x-n)>0) xi=(x+1)-(x-n)*2;
    else xi=x-1;
    if((y-n)>0) yi=(y+1)-(y-n)*2;
    else yi=y-1;
    ans+=xi*yi;
  }
  cout << ans << endl;
}