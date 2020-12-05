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
  int n;
  string t;
  cin >> n >> t;
  if(n==1 && t=="1"){
    cout << 10000000000*2 << endl;
    return 0;
  }
  if(n==1 && t=="0"){
    cout << 10000000000 << endl;
    return 0;
  }
  ll ans=0, cnt=0;
  rep(i,n-2){
    if(t.substr(i,3)=="110") cnt++;
    else if(t.substr(i,3)!="011" && t.substr(i,3)!="101"){
      cout << 0 << endl;
      return 0;
    }
  }
  if(t[0]=='1' && t[1]=='1' && t[n-2]=='1' && t[n-1]=='1') ans=1e10-cnt;
  if(t[0]=='1' && t[1]=='1' && t[n-2]=='1' && t[n-1]=='0') ans=1e10-cnt+1;
  if(t[0]=='1' && t[1]=='1' && t[n-2]=='0' && t[n-1]=='1') ans=1e10-cnt;
  if(t[0]=='1' && t[1]=='0' && t[n-2]=='1' && t[n-1]=='1') ans=1e10-cnt-1;
  if(t[0]=='1' && t[1]=='0' && t[n-2]=='1' && t[n-1]=='0') ans=1e10-cnt;
  if(t[0]=='1' && t[1]=='0' && t[n-2]=='0' && t[n-1]=='1') ans=1e10-cnt-1;
  if(t[0]=='0' && t[1]=='1' && t[n-2]=='1' && t[n-1]=='1') ans=1e10-cnt-1;
  if(t[0]=='0' && t[1]=='1' && t[n-2]=='1' && t[n-1]=='0') ans=1e10-cnt;
  if(t[0]=='0' && t[1]=='1' && t[n-2]=='0' && t[n-1]=='1') ans=1e10-cnt-1;
  cout << ans << endl;
}