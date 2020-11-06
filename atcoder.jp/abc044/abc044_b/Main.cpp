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
  string w;
  cin >> w;
  vi alpha(26);
  rep(i,w.size()){
    alpha[w[i]-'a']++;
  }
  int cnt=0;
  rep(i,26){
    if(alpha[i]%2==0) cnt++;
  }
  if(cnt==26) cout << "Yes" << endl;
  else cout << "No" << endl;
}