#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
//using mint = modint998244353;
using mint = modint1000000007;

int main(){
  string s;
  int q;
  cin >> s >> q;
  int rcnt=0;
  rep(i,q){
    int t;
    cin >> t;
    if(t==1) rcnt++;
    else{
      int f;
      string c;
      cin >> f >> c;
      if(f==1 && rcnt%2==0) s.insert(0, c);
      if(f==1 && rcnt%2==1) s.insert(s.size(), c);
      if(f==2 && rcnt%2==0) s.insert(s.size(), c);
      if(f==2 && rcnt%2==1) s.insert(0, c);
    }
  }
  if(rcnt%2==1) reverse(s.begin(), s.end());
  cout << s << endl;
}