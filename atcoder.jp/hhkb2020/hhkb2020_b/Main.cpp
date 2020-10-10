#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int h,w;
  cin >> h >> w;
  vector<string> s(110);
  rep(i,h) cin >> s[i];
  int cnt=0;
  rep(i,h)rep(j,w){
    if(s[i][j]=='.'&&s[i][j+1]=='.') cnt++;
    if(s[i][j]=='.'&&s[i+1][j]=='.') cnt++;
  }
  cout << cnt << endl;
}