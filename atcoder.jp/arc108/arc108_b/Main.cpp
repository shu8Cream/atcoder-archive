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
  int n;
  cin >> n;
  string s;
  cin >> s;
  stack<string> a;
  int ans=n;
  rep(i,n){
    if(!a.empty() && a.top()=="f" && s[i]=='o'){
      a.pop();
      a.push("fo");
      continue;
    }
    if(!a.empty() && a.top()=="fo" && s[i]=='x'){
      a.pop();
      ans-=3;
      continue;
    }
    string c{s[i]};
    a.push(c);
  }
  cout << ans << endl;
}