#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;

ll n;

bool isOK(ll index){
  if(index*(index+1)/2<=n) return true;
  else return false;
}

ll binary_search(ll n){
  ll ng = -1;
  ll ok = sqrt(n)*2;
  while(abs(ok - ng) > 1){
    ll mid = (ok + ng) / 2;
    if(isOK(mid)) ng = mid;
    else ok = mid;
  }
  return ok;
}

int main(){
  cin >> n;
  n++;
  ll m = binary_search(n);
  cout << n-m+1 << endl;
}