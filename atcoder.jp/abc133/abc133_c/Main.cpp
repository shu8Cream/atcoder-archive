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
  ll l,r;
  cin >> l >> r;
  ll lm=l%2019, rm=r%2019, ran=r-l;
  if(ran>=2019 || lm>=rm){
    cout << 0 << endl;
    return 0;
  }
  int ans=2019;
  for(int i=lm; i<rm; i++){
    for(int j=i+1; j<=rm; j++){
      ans=min(i*j%2019, ans);
    }
  }
  cout << ans << endl;
}