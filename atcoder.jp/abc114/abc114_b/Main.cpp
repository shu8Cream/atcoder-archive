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
  int ans=1000;
  rep(i,s.size()-2){
    int tmp=0;
    tmp+=(s[i]-'0')*100;
    tmp+=(s[i+1]-'0')*10;
    tmp+=s[i+2]-'0';
    ans=min(ans, abs(753-tmp));
  }
  cout << ans << endl;
}