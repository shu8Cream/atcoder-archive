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
  vi a(n),b(n);
  rep(i,n) cin >> a[i], b[i]=a[i];
  sort(b.begin(), b.end());
  rep(i,n){
    if(b[n-1]==a[i]) cout << b[n-2] << endl;
    else cout << b[n-1] << endl;
  }
}