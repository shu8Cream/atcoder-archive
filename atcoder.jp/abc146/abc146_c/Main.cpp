#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  ll a,b,x,n=0;
  cin >> a >> b >> x;
  
  auto keta = [&](ll n){
    ll res=0;
    while(n) ++res, n/=10;
    return res;
  };
  auto f = [&](ll n){
    return a*n + b*keta(n);
  };
  
  ll left=0, right=1e9+1;
  while(right -left > 1){
    ll mid = (left+right)/2;
    if(f(mid) > x) right=mid;
    else left=mid;
  }
  cout << left << endl;
}