#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  vi a(5);
  rep(i,5) cin >> a[i];
  int mx=0, ans=0;
  rep(i,5){
    mx=max(mx, (a[i]+10-1)/10*10-a[i]);
    ans+=(a[i]+10-1)/10*10;
  }
  ans-=mx;
  cout << ans << endl;
}