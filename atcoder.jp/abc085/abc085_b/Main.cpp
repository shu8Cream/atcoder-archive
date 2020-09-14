#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  vector<int> d(n);
  rep(i,n) cin >> d[i];
  int ans=0;
  sort(d.begin(),d.end());
  reverse(d.begin(),d.end());
  rep(i,n){
    if(d[i]>d[i+1]) ans++;
  }
  cout << ans << endl;
}