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
  int a,b,k;
  cin >> a >> b >> k;
  set<int> c;
  rep(i,k){
    if(a<=a+i && a+i<=b) c.insert(a+i);
  }
  rep(i,k){
    if(a<=b-i && b-i<=b) c.insert(b-i);
  }
  for (auto v : c){
    cout << v << endl;
  }
}