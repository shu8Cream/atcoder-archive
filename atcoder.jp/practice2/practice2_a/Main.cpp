#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using namespace atcoder;

int main(){
  int n,q;
  cin >> n >> q;
  vector<int> t(q);
  vector<int> u(q);
  vector<int> v(q);
  rep(i,q) cin >> t[i] >> u[i] >> v[i];
  dsu d(n);
  rep(i,q){
    if(t[i]==0) d.merge(u[i], v[i]);
    else{
      if(d.same(u[i], v[i])) cout << 1 << endl;
      else cout << 0 << endl;
    }
  }
}