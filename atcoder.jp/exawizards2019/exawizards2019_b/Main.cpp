#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;

int main(){
  int n;
  string s;
  cin >> n >> s;
  int cnt=0;
  rep(i,n) if(s[i]=='R') cnt++;
  if(cnt>n/2) cout << "Yes" << endl;
  else cout << "No" << endl;
}