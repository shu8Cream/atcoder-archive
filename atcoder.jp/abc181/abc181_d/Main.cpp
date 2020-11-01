#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using mint = modint998244353;
//using mint = modint1000000007;

int main(){
  string s;
  cin >> s;
  bool flag=0;
  vector<string> a;
  //string c;
  rep(i,111){
    int b=8*(i+14);
    a.push_back(to_string(b));
  }
  //cout << a[a.size()-1] << endl;
  rep(i,a.size()){
    rep(j,3){
      if(a[i][j]=='0'){
        swap(a[i], a[a.size()-1]);
        a.pop_back();
      }
    }
  }
  //rep(i,a.size()) cout << a[i] << endl;
  vi ms(9);
  rep(i,s.size()){
    ms[s[i]-'0'-1]++;
  }
  
  vvi ma(a.size(), vi(9));
  rep(i,a.size()){
    rep(j,3){
      if(a[i][j]=='0'){
        ma[i][0]=1e6;
        ma[i][1]=1e6;
        ma[i][2]=1e6;
        break;
      }
      int c=a[i][j]-'1';
      //cout << c << endl;
      ma[i][c]++;
    }
  }
  rep(i,a.size()){
    int cnt=0;
    rep(j,9){
      if(ma[i][j]<=ms[j]) cnt++;
    }
    if(cnt==9) flag=1;
  }
  if(flag) cout << "Yes" << endl;
  else if(s=="8" || s=="16" || s=="61" || s=="24" || s=="42" || s=="32" || s=="23" || s=="48" || s=="84" || s=="56" || s=="65" || s=="64" || s=="46" || s=="72" || s=="27") cout << "Yes" << endl;
  else cout << "No" << endl;
}