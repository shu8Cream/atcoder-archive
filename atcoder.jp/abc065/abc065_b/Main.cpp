#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  ll n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  int cnt=0;
  int b = a[0];
  while(1){
    cnt++;
    if(b==2) break;
    if(cnt==n+1) break;
    b = a[b-1];
  }
  if(cnt==n+1) cout << -1 << endl;
  else cout << cnt << endl;
}