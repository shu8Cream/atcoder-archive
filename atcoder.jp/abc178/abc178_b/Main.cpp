#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  ll a,b,c,d;
  cin >>a>>b>>c>>d;
  ll ans=-1000000000;
  if(a>=0 && c>=0){
    ans=b*d;
    cout << ans << endl;
    return 0;
  }
  if(a>=0 && d<=0){
    ans=a*d;
    cout << ans << endl;
    return 0;
  }
  if(b<=0 && c>=0){
    ans=b*c;
    cout << ans << endl;
    return 0;
  }
  if(b<=0 && d<=0){ 
    ans=a*c;
    cout << ans << endl;
    return 0;
  }
  ans=max(a*c,b*d);
  cout << ans << endl;
}