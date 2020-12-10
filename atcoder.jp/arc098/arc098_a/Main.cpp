#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;

int main(){
  int n;
  string s;
  cin >> n >> s;
  int ans=1e8;
  vi w(n),e(n);
  rep(i,n){
    if(s[i]=='W') w[i+1]=w[i]+1;
    else w[i+1]=w[i];
  }
  reverse(s.begin(), s.end());
  rep(i,n){
    if(s[i]=='E') e[i+1]=e[i]+1;
    else e[i+1]=e[i];
  }
  reverse(e.begin(), e.end());
  rep(i,n) ans=min(ans, e[i]+w[i]);
  cout << ans << endl;
}
