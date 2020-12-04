#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;

int main(){
  int n,va,vb,l;
  cin >> n >> va >> vb >> l;
  double ans=l;
  rep(i,n){
    ans=ans/va*vb;
  }
  printf("%.10f", ans);
}