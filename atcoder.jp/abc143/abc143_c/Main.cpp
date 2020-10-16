#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n,cnt=1;
  cin >> n;
  string s;
  cin >> s;
  char tmp=s[0];
  rep(i,n-1){
    if(tmp==s[i+1]) continue;
    else cnt++;
    tmp=s[i+1];
  }
  cout << cnt << endl;
}