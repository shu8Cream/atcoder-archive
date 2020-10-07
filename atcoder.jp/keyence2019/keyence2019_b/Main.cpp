#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const string key = "keyence";

int main(){
  string s,t;
  cin >> s;
  int cnt=s.size()-7;
  rep(i,s.size()-cnt){
    t=s;
    rep(j,cnt){
      t[i+j]='A';
    }
    string l;
    rep(j,s.size()){
      if(t[j]!='A') l.push_back(s[j]);
    }
    if(l==key){
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" <<endl;
}