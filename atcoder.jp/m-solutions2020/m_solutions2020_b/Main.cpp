#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int a,b,c,k;
  cin >> a >> b >> c >> k;
  while(a>=b){
    b*=2;
    --k;
  }
  while(b>=c){
    c*=2;
    --k;
  }
  if(k>=0) cout << "Yes" << endl; 
  else cout << "No" << endl;
}