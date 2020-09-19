#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  ll cnt=0;
  int a=1,b=1;
  for(int a=1; a*b<n; a++){
    for(int b=1; a*b<n; b++){
      cnt++;
    }
  }
  cout << cnt << endl;
}