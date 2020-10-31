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
  string s;
  cin >> s;
  sort(s.begin(), s.end());
  if(s[0]!=s[2] && s[0]==s[1] && s[2]==s[3]) cout << "Yes" << endl;
  else cout << "No" << endl;
}