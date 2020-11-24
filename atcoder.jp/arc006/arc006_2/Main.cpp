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
  int n,l;
  cin >> n >> l;
  vector<string> s(l+2);
  rep(i,l+2) getline(cin, s[i]);
  int g=0;
  rep(i,n){
    if(s[l+1][i*2]=='o') g=i*2;
  }
  for(int i=l; i>=1; i--){
    int gi=g;
    if(gi+1<2*n && s[i][gi+1]=='-') g+=2;
    if(gi-1>=0 && s[i][gi-1]=='-') g-=2;
  }
  cout << g/2+1 << endl;
}