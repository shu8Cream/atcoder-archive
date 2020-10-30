#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
//using mint = modint1000000007;

ll f(ll n){
  if(n<0) return 0;
  if(n%2==1 && (n+1)/2%2==0) return 0;
  else if(n%2==1 && (n+1)/2%2==1) return 1;
  else if(n%2==0 && n/2%2==1) return 1^n;
  else if(n%2==0 && n/2%2==0) return 0^n;
}

int main(){
  ll a,b;
  cin >> a >> b;
  ll ans=f(b)^f(a-1);
  cout << ans << endl;
}