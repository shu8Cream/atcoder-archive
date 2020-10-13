#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n, k;
  cin >> n >> k;
  vector<int> h(n);
  rep(i,n) cin >> h[i];
  sort(h.begin(), h.end());
  while(k--) if(!h.empty()) h.pop_back();
  ll sum=0;
  rep(i,h.size()) sum+=h[i];
  cout << sum << endl;
}