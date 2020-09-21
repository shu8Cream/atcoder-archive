#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll mod = 1e9+7;

int main(){
  int n;
  cin >> n;
  ll pw=1;
  for(int i=1; i<=n; i++){
    pw=pw*i%mod;
  }
  cout << pw << endl;
}