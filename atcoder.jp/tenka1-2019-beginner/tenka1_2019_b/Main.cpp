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

int main(){
  int n,k;
  string s;
  cin >> n >> s >> k;
  rep(i,n){
    if(s[k-1]!=s[i]) s[i]='*';
  }
  cout << s << endl;
}