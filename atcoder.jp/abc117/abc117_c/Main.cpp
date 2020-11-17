#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;

int main(){
  int n,m;
  cin >> n >> m;
  vi x(m),y(m-1);
  rep(i,m) cin >> x[i];
  sort(x.begin(), x.end());
  rep(i,m-1) y[i]=x[i+1]-x[i];
  sort(y.begin(), y.end());
  int ans=0;
  if(n<m){
    rep(i,n-1) y.pop_back();
    rep(i,y.size()) ans+=y[i];
  }
  cout << ans << endl;
}