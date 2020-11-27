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
  string s;
  cin >> s;
  int cnt=0;
  rep(i,6) if(s[i]=='1') cnt++;
  cout << cnt << endl;
}