#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;

int main(){
  int n;
  cin >> n;
  vi t(n);
  rep(i,n) cin >> t[i];
  int sum1,sum2,ans=20000;
  rep(s,1<<n){
    sum1=0; sum2=0;
    rep(i,n){
      if(s>>i&1) sum1+=t[i];
      else sum2+=t[i];
    }
    ans=min(ans,max(sum1,sum2));
  }
  cout << ans << endl;
}