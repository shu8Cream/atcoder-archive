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
  bool f=1;
  rep(i,s.size()){
    if(s[i]=='/') cnt++;
    if(s[i]=='0') cnt++;
    if(cnt==3 && s[i]>'4'){
      f=0;
      break;
    }
    if(cnt==2 && s[i]=='1'){
      f=0;
      break;
    }
  }

  if(f) cout << "Heisei" << endl;
  else cout << "TBD" << endl;
}