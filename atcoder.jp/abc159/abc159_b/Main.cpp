#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  string s;
  cin >> s;
  string t = s;
  reverse(s.begin(),s.end());
  string sb = s.substr(0,(s.size()-1)/2);
  string tb = sb;
  reverse(sb.begin(),sb.end());
  string se = s.substr((s.size()+1)/2,s.size()-1);
  string te = se;
  reverse(se.begin(),se.end());
  if(s==t && sb==tb && se==te) cout << "Yes" << endl;
  else cout << "No" << endl;
}