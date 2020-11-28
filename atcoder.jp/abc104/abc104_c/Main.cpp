#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;

int main(){
  int d,g;
  cin >> d >> g;
  vi p(d),c(d);
  rep(i,d) cin >> p[i] >> c[i];
  ll ans=1<<29;
  for(int bit=0; bit<(1<<d); bit++){
    ll num=0, sumsc=0;
    rep(i,d){
      if(bit & (1<<i)) sumsc+=c[i]+p[i]*100*(i+1), num+=p[i];
    }
    if(sumsc>=g) ans=min(ans, num);
    else{
      for(int i=d-1; i>=0; i--){
        if(bit & (1<<i)) continue;
        rep(j,p[i]){
          if(sumsc>=g) break;
          sumsc+=100*(i+1);
          num++;
        }
      }
      ans=min(ans, num);
    }
  }
  
  cout << ans << endl;
}