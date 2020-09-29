#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  string c;
  cin >> c;
  int rf=0,ra=0;
  rep(i,n){
    if(c[i]=='R') ra++;
  }
  rep(i,ra){
    if(c[i]=='R') rf++;
  }
  cout << ra-rf <<endl;
}