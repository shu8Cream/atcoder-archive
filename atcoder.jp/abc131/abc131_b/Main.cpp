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
  int n,l;
  cin >> n >> l;
  vi a(n), b(n);
  rep(i,n){
    a[i]=l+i;
    b[i]=abs(a[i]);
  }
  sort(b.begin(), b.end());
  int sum=0;
  rep(i,n){
    if(b[0]==a[i] || b[0]==-a[i]) continue;
    else sum+=a[i];
  }
  cout << sum << endl;
}