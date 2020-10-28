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
  vi a(n);
  rep(i,n) cin >> a[i];
  map<int, int> s;
  rep(i,n) s[a[i]]++;
  int ans=0;
  for (auto p : s) {
    auto k = p.first;
    auto v = p.second;
    if(k!=v && k>v) ans+=v;
    if(k!=v && k<v) ans+=v-k;
  }
  cout << ans << endl;
}