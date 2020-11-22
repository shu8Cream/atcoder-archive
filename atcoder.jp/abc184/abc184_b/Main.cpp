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
  int n,x;
  cin >> n >> x;
  string s;
  cin >> s;
  rep(i,s.size()){
    if(s[i]=='o') x++;
    if(s[i]=='x' && x>0) x--;
  }
  cout << x << endl;
}