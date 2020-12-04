#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;

int main(){
  string s;
  cin >> s;
  int n = s.size();
  // sが最初から回文かどうか
  int cnt=0;
  rep(i,n){
    if(s[i]==s[n-1-i]) cnt++;
  }
  if(cnt==n){
    cout << 0 << endl;
    return 0;
  }
  //そもそも回文が作れるか
  string a;
  rep(i,n) if(s[i]!='x') a+=s[i];
  rep(i,a.size()){
    if(a[i]!=a[a.size()-1-i]){
      cout << -1 << endl;
      return 0;
    }
  }
  vi b;
  cnt=0;
  rep(i,n){
    if(s[i]=='x') cnt++;
    else{
      b.push_back(cnt);
      cnt=0;
    }
    if(i==n-1) b.push_back(cnt);
  }
  int ans=0;
  rep(i,b.size()/2){
    if(b[i]!=b[b.size()-1-i]) ans+=abs(b[i]-b[b.size()-1-i]);
  }
  cout << ans << endl;
}