#include <bits/stdc++.h>
#define rep(i,n) for (ll i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  ll h,w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i,h) cin >> s[i];
  rep(i,h)rep(j,w){
    if(s[i][j]=='.') s[i][j]='0';
    if(s[i][j]=='#') continue;
    if(s[i][j+1]=='#') s[i][j]++;
    if(s[i][j-1]=='#') s[i][j]++;
    if(i+1<h){
      if(s[i+1][j+1]=='#') s[i][j]++;
      if(s[i+1][j]=='#') s[i][j]++;
      if(s[i+1][j-1]=='#') s[i][j]++;
    }
    if(i-1>-1){
      if(s[i-1][j-1]=='#') s[i][j]++;
      if(s[i-1][j]=='#') s[i][j]++;
      if(s[i-1][j+1]=='#') s[i][j]++;
    }
  }
  rep(i,h) cout << s[i] << endl;
}