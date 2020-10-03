#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  string s;
  cin >> n >> s;
  ll ans=0;
  rep(left, n){
    int cnta=0,cntt=0,cntc=0,cntg=0;
    for(int right=left; right<n; right++){
      if(s[right]=='A') cnta++;
      else if(s[right]=='T') cntt++;
      else if(s[right]=='C') cntc++;
      else cntg++;
      if(cnta==cntt && cntc==cntg) ans++;
    }
  }
  cout << ans << endl;
}