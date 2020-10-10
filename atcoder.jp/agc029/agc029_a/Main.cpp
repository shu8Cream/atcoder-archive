#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  string s;
  cin >> s;
  ll cnt=0,l=0;
  for(int i=s.size()-1; i>=0; --i){
    if(s[i]=='B'){
      cnt+=s.size()-1-l-i;
      l++;
    }
  }
  cout << cnt << endl;
}