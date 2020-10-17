#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i,n) cin >> s[i];
  rep(i,n) sort(s[i].begin(), s[i].end());
  ll cnt=0;
  map<string, ll> a;
  rep(i,n){
    if(a.count(s[i])) a[s[i]]++;
    else a[s[i]]=1;
  }
  for (auto p : a) {
    auto v = p.second;
    if(v>1) cnt+=v*(v-1)/2;
  }
  cout << cnt << endl;
}