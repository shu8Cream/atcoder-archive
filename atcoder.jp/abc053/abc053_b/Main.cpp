#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  string s;
  cin >> s;
  bool ok=false;
  int cnt=s.size()+1;
  rep(i,s.size()){
    if(s[i]!='A') cnt--;
    else break;
  }
  for(int i=s.size(); i>=0; i--){
    if(s[i]!='Z') cnt--;
    else break;
  }
  cout << cnt << endl;
}