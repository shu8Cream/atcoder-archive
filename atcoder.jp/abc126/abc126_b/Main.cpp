#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
//using mint = modint998244353;
//using mint = modint1000000007;

int main(){
  int s;
  cin >> s;
  int s2=s-s/100*100;
  if(s2<13 && s2>0 && s/100<13 && s/100>0) cout << "AMBIGUOUS" << endl;
  else if(s2<13 && s2>0) cout << "YYMM" << endl;
  else if(s/100<13 && s/100>0)cout << "MMYY" << endl;
  else cout << "NA" << endl;
}