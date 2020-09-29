#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int a,b;
  cin >> a >> b;
  vector<int> x(a, b);
  vector<int> y(b, a);
  if(x<y){
    rep(i,a) cout << x[i];
    cout << endl;
  }else{
    rep(i,b) cout << y[i];
    cout << endl;
  }
}