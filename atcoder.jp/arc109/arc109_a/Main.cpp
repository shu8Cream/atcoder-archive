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
  int a,b,x,y;
  cin >> a >> b >> x >> y;
  int ans=0;
  if(a<b){
    if(x>y) ans=abs(a-b)*y+x;
    else{
      if(2*x>y) ans=y*abs(a-b)+x;
      else ans=2*x*abs(a-b)+x;
    }
  }else{
    if(x>y) ans=abs(a-b)*y+x-y;
    else{
      if(2*x>y) ans=y*abs(a-b)+x-y;
      else ans=2*x*abs(a-b)-x;
    }
  }
  if(abs(a-b)==1 && a>=b) ans=x;
  else if(abs(a-b)==1 && a<b){
    if(2*x>y) ans=x+y;
    else ans=3*x;
  }
  if(a-b==0) ans=x;
  cout << ans << endl;
}