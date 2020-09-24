#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n,m;
  cin >> n >> m;
  vector<int> s(m);
  vector<int> c(m);
  rep(i,m) cin >> s[i] >> c[i];
  rep(i,m)rep(j,m){
    if(s[i]==s[j] && c[i]!=c[j]){
      cout << -1 << endl;
      return 0;
    }
  }
  int h=0,t=0,o=0;
  if(n==3) h=100;
  if(n==2) t=10;
  rep(i,m){
    if(s[i]==1 && c[i]==0 && n!=1){
      cout << -1 << endl;
      return 0;
    }
    if(n==3 && s[i]==1) h=100*c[i];
    if(n==3 && s[i]==2) t=10*c[i];
    if(n==3 && s[i]==3) o=c[i];
    if(n==2 && s[i]==1) t=10*c[i];
    if(n==2 && s[i]==2) o=c[i];
    if(n==1 && s[i]==1) o=c[i];
  }
  int ans=h+t+o;
  cout << ans << endl;
}