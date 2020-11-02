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
//using mint = modint1000000007;

int main(){
  int n;
  cin >> n;
  vi w(n);
  rep(i,n) cin >> w[i];
  //int s1=0, s2=0;
  int ans=1e6;
  rep(i,n){
    int s1=0, s2=0;
    rep(j,i+1){
      s1+=w[j];
    }
    for(int j=i+1; j<n; ++j){
      s2+=w[j];
    }
    ans=min(ans, abs(s1-s2));
  }
  cout << ans << endl;
}