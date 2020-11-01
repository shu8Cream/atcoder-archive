#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using mint = modint998244353;
//using mint = modint1000000007;

int main(){
  int n;
  cin >> n;
  vi x(n), y(n);
  rep(i,n) cin >> x[i] >> y[i];
  bool flag=0;
  rep(i,n){
    for(int j=i+1; j<n; j++){
      for(int k=j+1; k<n; k++){
        if((x[j]-x[i])*y[k]==(y[j]-y[i])*x[k]+y[i]*x[j]-y[j]*x[i]) flag=1;
      }
    }
  }
  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
}