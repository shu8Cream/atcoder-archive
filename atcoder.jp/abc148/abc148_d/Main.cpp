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
  int n;
  cin >> n;
  vi a(n);
  rep(i,n) cin >> a[i];
  int cnt=1;
  rep(i,n){
    if(a[i]==cnt) cnt++;
  }
  if(n-(cnt-1)==n) cout << -1 << endl;
  else cout << n-(cnt-1) << endl;
}