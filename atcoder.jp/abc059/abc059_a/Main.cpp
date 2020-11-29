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

int main(){
  vector<string> s(3);
  rep(i,3) cin >> s[i];
  rep(i,3) cout << char(s[i][0]+'A'-'a');
}