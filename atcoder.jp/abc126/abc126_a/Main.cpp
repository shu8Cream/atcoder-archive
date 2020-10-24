#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
//using mint = modint998244353;
//using mint = modint1000000007;

int main(){
  int n,k;
  string s;
  cin >> n >> k >> s;
  rep(i,s.size()){
    if(i==k-1) cout << char(s[i]-('A'-'a'));
    else cout << s[i];
  }
}