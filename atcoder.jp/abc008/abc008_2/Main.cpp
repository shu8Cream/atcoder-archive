#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  map<string, int> cnt;
  rep(i,n){
    string s;
    cin >> s;
    cnt[s]++;
  }
  string k;
  int v,vm=0;
  for (auto p : cnt) {
    v = p.second;
    vm=max(vm, v);
    if(vm==v) k = p.first;
  }
  cout << k << endl;
}