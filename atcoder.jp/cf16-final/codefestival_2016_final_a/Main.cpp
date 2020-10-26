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
  int h,w;
  cin >> h >> w;
  vector<vector<string>> s(h, vector<string>(w));
  rep(i,h)rep(j,w) cin >> s[i][j];
  rep(i,h){
    rep(j,w){
      if(s[i][j]=="snuke") cout << char('A'+j) << i+1 << endl;
    }
  }
}