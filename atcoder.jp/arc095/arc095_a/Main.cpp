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
  vi x(n), a(n);
  rep(i,n) cin >> x[i], a[i]=x[i];
  sort(a.begin(), a.end());
  rep(i,n){
    if(x[i]<a[n/2]) cout << a[n/2] << endl;
    else cout << a[n/2-1] << endl;
  }
}