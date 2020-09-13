#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin>>n;
  int ans=0;
  rep(i,n){
    if(n<10) ans=n;
    if(n<100&&n>9) ans=9;
    if(n<1000&&n>99) ans=9+n-99;
    if(n<10000&&n>999) ans=909;
    if(n<100000&&n>9999) ans=909+n-9999;
    if(n==100000) ans=90909;
  }
  cout << ans << endl;
}