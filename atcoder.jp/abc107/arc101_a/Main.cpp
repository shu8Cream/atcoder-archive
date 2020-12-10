#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;

int main(){
  int n,k;
  cin >> n >> k;
  vi x(n);
  rep(i,n) cin >> x[i];
  int ans=1e9;
  rep(i,n-k+1){
    if(x[i]<0 && x[i+k-1]<=0) {ans=min(ans, abs(x[i])); continue;}
    if(x[i]>=0 && x[i+k-1]>0) {ans=min(ans, abs(x[i+k-1])); continue;}
    if(abs(x[i])>abs(x[i+k-1])) ans=min(ans,abs(x[i+k-1])*2+abs(x[i]));
    else ans=min(ans, abs(x[i])*2+abs(x[i+k-1]));
  }
  cout << ans << endl;
}
