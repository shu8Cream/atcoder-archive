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
//using mint = modint1000000007;

int main(){
  int n,k;
  cin >> n >> k;
  double ans=0;
  int e=0;
  rep(i,n){
    int p=i+1;
    for(int j=0; j<20; ++j){
      if(p>=k){
        e=j;
        break;
      }
      p*=2;
    }
    ans+=(double)pow(0.5, e)/n;
    //printf("%.10lf\n", ans);
  }
  printf("%.15lf", ans);
}