#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  string s;
  cin >> s;
  if(s[s.size()-1]!='s'){
    s.push_back('s');
  }else{
    s.push_back('e');
    s.push_back('s');
  }
  cout << s << endl;
}