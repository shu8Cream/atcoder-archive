#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int a,b;
  cin >> a >> b;
  rep(i,2000){
    if(int(i*0.08)==a && int(i*0.1)==b){
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}