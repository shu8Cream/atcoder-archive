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
  int n=s.size(),num=0;
  ll ans=0;
  rep(i,n-2){
    if(s[i]=='A' && s[i+1]=='B' && s[i+2]=='C'){
      ans+=num+1;
      s[i+2]='A';
      i++;
    }else if(s[i]=='A') num++;
    else num=0;
  }
  cout << ans << endl;
}