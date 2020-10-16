#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  string s;
  cin >> s;
  int cnta=0, cntb=0, cntc=0;
  rep(i,s.size()){
    if(s[i]=='a') cnta++;
  }
  rep(i,s.size()){
    if(s[i]=='b') cntb++;
  }
  rep(i,s.size()){
    if(s[i]=='c') cntc++;
  }
  if(cnta==1&&cntb==1&&cntc==1) cout << "Yes" << endl;
  else cout << "No" << endl;
}