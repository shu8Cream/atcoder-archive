#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin>>n;
  vector<int> t(n+1);
  vector<int> x(n+1);
  vector<int> y(n+1);
  rep(i,n) cin>>t[i+1]>>x[i+1]>>y[i+1];
  bool can = true;
  rep(i,n){
    int dt=t[i+1]-t[i];
    int dist = abs(x[i+1]-x[i])+abs(y[i+1]-y[i]);
    if(dt<dist) can = false;
    if(dist%2 != dt%2) can = false;
  }
  if(can) cout << "Yes" << endl;
  else cout << "No" << endl;
}