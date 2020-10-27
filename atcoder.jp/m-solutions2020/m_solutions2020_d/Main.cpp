#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n;
  cin >> n;
  vi a(n+1);
  rep(i,n) cin >> a[i+1];
  ll mymoney=1000;
  rep(i,n-1){
    ll stock=0;
    if(a[i+1]<a[i+2]) stock=mymoney/a[i+1];
    mymoney+=(a[i+2]-a[i+1])*stock;
  }
  cout << mymoney << endl;
}