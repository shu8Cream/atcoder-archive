#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  rep(i,s.size()){
    if(s[i]+n>90) s[i]+=n-26;
    else s[i]+=n;
  }
  cout << s << endl;
}