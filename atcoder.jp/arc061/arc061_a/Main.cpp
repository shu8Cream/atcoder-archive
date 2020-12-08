#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;

int main(){
  string s;
  cin >> s;
  int n = s.size();
  ll ans=0;
  int cnt=1;
  rep(b,1<<(n-1)){
    ans+=s[n-1]-'0';
    cnt=1;
    rep(i,n-1){
      if(b>>i&1){
        ans+=s[n-2-i]-'0';
        cnt=1;
      }else{
        ans+=(s[n-2-i]-'0')*pow(10,cnt);
        cnt++;
      }
    }
  }
  cout << ans << endl;
}