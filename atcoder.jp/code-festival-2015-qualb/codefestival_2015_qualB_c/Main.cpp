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
  int n,m;
  cin >> n >> m;
  vi a(n),b(m);
  rep(i,n) cin >> a[i];
  rep(i,m) cin >> b[i];
  sort(a.rbegin(), a.rend());
  sort(b.rbegin(), b.rend());
  bool f=1;
  if(n<m) f=0;
  else{
    rep(i,m) if(a[i]<b[i]) f=0;
  }
  if(f) cout << "YES" << endl;
  else cout << "NO" << endl;
}