#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> ae(n+1,0);
  vector<int> aw(n+1,0);
  vector<int> a(n,0);
  rep(i,n){
    if(s[i]=='W') a[i]=1;
    else a[i]=0;
    aw[i+1]=aw[i]+a[i];
  }
  rep(i,n){
    if(s[i]=='E') a[i]=1;
    else a[i]=0;
    ae[i+1]=ae[i]+a[i];
  }
  vector<int> ans(n);
  rep(i,n) ans[i]=aw[i]+ae[n]-ae[i+1];
  sort(ans.begin(), ans.end());
  cout << ans[0] << endl;
}