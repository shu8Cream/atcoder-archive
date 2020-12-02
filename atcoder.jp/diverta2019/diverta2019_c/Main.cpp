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
  cin >> n;
  vector<string> s(n);
  rep(i,n) cin >> s[i];
  int a=0,b=0,ba=0;
  rep(i,n){
    if(s[i][0]=='B' && s[i][s[i].size()-1]=='A') ba++;
    if(s[i][0]=='B') b++;
    if(s[i][s[i].size()-1]=='A') a++;
  }
  int ab=0;
  rep(i,n){
    rep(j,s[i].size()-1){
      if(s[i][j]=='A' && s[i][j+1]=='B') ab++;
    }
  }
  if(a==ba && b==ba) cout << ab+max(0, ba-1) << endl;
  else cout << ab+min(a,b) << endl;
}