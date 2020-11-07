#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
//using mint = modint998244353;
using mint = modint1000000007;

int main(){
  int n,q;
  string s;
  cin >> n >> q >> s;
  vi cntac(n);
  rep(i,n){
    if(i==0) continue;
    cntac[i]+=cntac[i-1];
    if(s[i-1]=='A' && s[i]=='C') cntac[i]++;
  }
  rep(i,q){
    int l,r;
    cin >> l >> r;
    cout << cntac[r-1]-cntac[l-1] << endl;
  }
}