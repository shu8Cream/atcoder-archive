#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  vector<int> x(n);
  rep(i,n) cin >> x[i];
  ll m=0,t=0;
  double y=0;
  rep(i,n){
    ll j=abs(x[i]);
    m+=j;
    y+=j*j;
    t=max(j,t);
  }
  cout << m << endl;
  printf("%.12lf\n", sqrt(y));
  cout << t << endl;
}