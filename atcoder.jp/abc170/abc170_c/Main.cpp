#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int x,n;
  cin >> x >> n;
  vector<int> p(n); rep(i,n) cin>>p[i];
  vector<int> pa(n); rep(i,n) cin>>pa[i];
  rep(i,n) pa[i]=abs(p[i]-x);
  sort(pa.begin(),pa.end());
  int diff=0,ans=0;
  int cnt=0;
  rep(i,n){
    if(pa[i]!=0) cnt++;
  }
  if(cnt==n) diff=0;
  else{
    for(int i=1; i<101; i++){
      cnt=0;
      for(int j=1; j<n; j++){
        if(pa[j]==i) cnt++;
      }
      if(cnt!=2){
        diff=i;
        break;
      }
    }
  }
  rep(i,n){
    ans=x+diff;
    if(p[i]==x-diff) break;
    ans=x-diff;
    if(p[i]==x+diff) break;
  }
  if(n==0) ans=x;
  cout << ans << endl;
}