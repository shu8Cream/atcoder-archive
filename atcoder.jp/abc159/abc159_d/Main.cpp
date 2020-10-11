#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  map<int,int> b;
  rep(i,n) b[a[i]]++;
  ll ans=0,all=0;
  for (auto p : b) {
    ll v = p.second;
    all+=v*(v-1)/2;
  }
  rep(i,n){
    ans=all-b[a[i]]+1;
    cout << ans << endl;
  }
}