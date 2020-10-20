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

int f(int n){
  int ret=0;
  while(n){
    ret+=n;
    n--;
  }
  return ret;
}

int main(){
  int n,k;
  cin >> n >> k;
  vi p(n);
  vector<double> q(n), r(n+1);
  rep(i,n) cin >> p[i], q[i]=double(1+p[i])/2;
  r[0]=0;
  rep(i,n) r[i+1]=r[i]+q[i];
  double ans=0;
  rep(i,n){
    double tmp=r[i+k]-r[i];
    ans=max(ans, tmp);
  }
  printf("%.07lf\n", ans);
}