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
  vi x(n),y(n);
  rep(i,n) cin >> x[i] >> y[i];
  double ans=0;
  rep(i,n){
    for(int j=i+1; j<n; j++){
      int l = (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
      ans=max(ans, sqrt(l));
    }
  }
  printf("%.10lf", ans);
}