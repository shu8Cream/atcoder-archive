#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;

int main(){
  int n;
  string s;
  cin >> n >> s;
  int mxl=0, tmp=0;
  rep(i,n){
    if(s[i]=='#') tmp=0;
    else tmp++;
    mxl=max(mxl, tmp);
  }
  int le=0, re=0;
  rep(i,n){
    if(s[i]=='#') break;
    else le++;
  }
  for(int i=n-1; i>=0; i--){
    if(s[i]=='#') break;
    else re++;
  }
  if(le+re==mxl) cout << le << " " << re << endl;
  else if(le+re<mxl && le<re) cout << le << " " << mxl-le << endl;
  else if(le+re<mxl && le>=re) cout << mxl-re << " " << re << endl;
  else if(le+re>mxl) cout << le << " " << re << endl;
  else if(le<re) cout << le << " " << mxl << endl;
  else cout << mxl << " " << re << endl;
} 