#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  vector<int> p(n);
  rep(i,n) cin >> p[i];
  int ans=0;
  int curMin=1e9;
  rep(i,n){
    curMin = min(curMin, p[i]);
    if(curMin == p[i]) ans++;
  }
  cout << ans << endl;
}