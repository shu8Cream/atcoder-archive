#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n,m;
  cin >> n >> m;
  vector<int> a(m), b(m);
  vector<int> c(n);
  rep(i,m) cin >> a[i] >> b[i];
  rep(i,m){
    c[a[i]-1]++;
    c[b[i]-1]++;
  }
  rep(i,n) cout << c[i] << endl;
}