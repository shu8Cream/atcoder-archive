#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  ll n;
  cin >> n;
  stack<ll> s;
  for(ll i=1; i*i<=n; i++){
    if(n/i!=i && n%i==0) s.push(n/i);
    if(n%i==0) cout << i << endl;
  }
  while(!s.empty()){
    cout << s.top() << endl;
    s.pop();
  }
}