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

int main(){
  string s;
  cin >> s;
  if(s[0]==s[1]||s[2]==s[1]||s[2]==s[3]) cout << "Bad" << endl;
  else cout << "Good" <<endl;
}