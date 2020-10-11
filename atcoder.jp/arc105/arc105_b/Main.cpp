#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  set<ll> a;
  rep(i,n){
    int b;
    cin >> b;
    a.insert(b);
  }
  ll X=*rbegin(a);
  ll x=*begin(a);
  while(x!=X){
    a.insert(X-x);
    a.erase(X);
    X=*rbegin(a);
    x=*begin(a);
  }
  cout << X << endl;
}