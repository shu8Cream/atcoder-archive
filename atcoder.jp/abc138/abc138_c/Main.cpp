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
  vector<double> v(n);
  rep(i,n) cin >> v[i];
  sort(v.begin(), v.end());
  double ans=0;
  rep(i,n-1){
    v[i+1]=double(v[i]+v[i+1])/2;
  }
  printf("%.06lf", v[n-1]);
}