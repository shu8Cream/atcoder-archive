#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int k;
  string s;
  cin>>k>>s;
  if(k>=s.size()) cout << s << endl;
  else{
    rep(i,k) cout << s[i];
    cout << "..." << endl;
  }
}