#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  ll x,y,a,b,k=0;
  cin >> x >> y >> a >> b;
  while(y/a>x && x*a<x+b && x*a<y){
    x*=a;
    k++;
  }
  k+=(y-x-1)/b;
  cout << k << endl;
}