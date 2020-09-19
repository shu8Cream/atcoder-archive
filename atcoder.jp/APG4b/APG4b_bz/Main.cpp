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
  map<int,int> md;
  rep(i,n){
    md[a[i]]++;
  }
  int ans1=0,ans2=0,v=0;
  for (int x : a) {
    if(ans2<md[x]){
      ans2 = md[x];
      ans1 = x;
    }
  }
  cout << ans1 << " " << ans2 << endl;
}