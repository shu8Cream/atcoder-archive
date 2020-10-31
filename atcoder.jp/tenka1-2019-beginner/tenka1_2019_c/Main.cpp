#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
//using mint = modint1000000007;

int main(){
  int n;
  string s;
  cin >> n >> s;
  ll ans=n, w=0, b=0;
  rep(i,n){
    if(s[i]=='.') w++;
  }
  rep(i,n){
    if(s[i]=='.'){
      w--;
      ans=min(b+w, ans);
    }else{
      ans=min(b+w, ans);
      b++;
    }
  }
  cout << ans << endl;
}