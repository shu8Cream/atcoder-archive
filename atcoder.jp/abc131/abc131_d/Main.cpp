#include <bits/stdc++.h>
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
  int n;
  cin >> n;
  vector<P> p(n);
  rep(i,n){
    int a,b;
    cin >> a >> b;
    p[i].first=b;
    p[i].second=-a;
  }
  sort(p.begin(), p.end());
  vi c(n);
  rep(i,n){
    if(i==0) c[i]=p[i].second;
    else c[i]=p[i].second+c[i-1];
  }
  rep(i,n) c[i]*=-1;
  bool f=1;
  rep(i,n) if(p[i].first<c[i]) f=0;
  if(f) cout << "Yes" << endl;
  else cout << "No" << endl;
}