#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
//using mint = modint998244353;

int main(){
  int n;
  cin >> n;
  vi h(n);
  rep(i,n) cin >> h[i];
  int ans=0,tmp=0;
  rep(i,n-1){
    if(h[i]>=h[i+1]) tmp++;
    else tmp=0;
    ans=max(ans, tmp);
  }
  cout << ans << endl;
}