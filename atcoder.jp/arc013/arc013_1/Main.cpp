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
  int n,m,l;
  cin >> n >> m >> l;
  vi pqr(3);
  rep(i,3) cin >> pqr[i];
  sort(pqr.begin(), pqr.end());
  int ans=0;
  do{
    ans=max(ans,(n/pqr[0]) * (m/pqr[1]) * (l/pqr[2]));
  }while(next_permutation(pqr.begin(), pqr.end()));
  cout << ans << endl;
}