#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  map<string,int> s;
  rep(i,n){
    string t;
    cin >> t;
    s[t]++;
  }
  int mx=0;
  for (auto p : s) {
    auto v = p.second;
    mx=max(mx,v);
  }
  for (auto p : s) {
    auto k = p.first;
    auto v = p.second;
    if(v==mx) cout << k << endl;
  }
}