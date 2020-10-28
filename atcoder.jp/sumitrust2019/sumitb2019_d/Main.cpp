#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans=0;
  rep(i,1000){
    string t;
    int x=i;
    rep(j,3){
      t+='0'+x%10;
      x/=10;
    }
    int ti=0;
    rep(j,n){
      if(s[j]==t[ti]){
        ++ti;
        if(ti==3) break;
      }
    }
 	if(ti==3) ans++;
  }
  cout << ans << endl;
}