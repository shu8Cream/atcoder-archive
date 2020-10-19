#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  string s,t;
  cin >> s >> t;
  int cnt=0;
  rep(i,3) if(s[i]==t[i]) cnt++;
  cout << cnt << endl;
}