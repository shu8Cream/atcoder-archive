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
  rep(i,n/2){
    if(s[i]!=s[n/2+i]){
      cout << "No" << endl;
      return 0;
    }
  }
  if(n%2==1) cout << "No" << endl;
  else cout << "Yes" << endl;
}