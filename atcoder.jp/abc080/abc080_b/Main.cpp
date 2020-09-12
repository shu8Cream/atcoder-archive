#include <bits/stdc++.h>
#define rep(i,n) for (ll i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  string n;
  cin >> n;
  ll x=0,a=0;
  rep(i,n.size()){
      x+=n[i]-'0';
  }
  rep(i,n.size()){
      a+=(n[i]-'0')*pow(10,n.size()-i-1);
  }
  if(a%x==0) cout << "Yes" << endl;
  else cout << "No" <<endl;
}