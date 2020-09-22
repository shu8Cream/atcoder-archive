#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  ll a,b,c;
  cin >> a >> b >> c;
  rep(i,b+1){
    if(a*i%b==c){
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}