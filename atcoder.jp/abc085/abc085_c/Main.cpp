#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<=(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  ll n,y;
  cin >> n >> y;
  rep(i,n)rep(j,n-i){
    if(y==i*10000+j*5000+(n-i-j)*1000){
      cout << i << " " << j << " " << n-i-j << endl;
      return 0;
    }
  }
  cout << "-1 -1 -1" << endl; 
}