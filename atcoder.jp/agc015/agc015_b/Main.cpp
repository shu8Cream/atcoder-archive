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
  string s;
  cin >> s;
  int n=s.size();
  ll ans=0;
  rep(i,n){
    if(s[i]=='U') ans+=n-1-i+i*2;
    else ans+=i+(n-1-i)*2;
  }
  cout << ans << endl;;
}