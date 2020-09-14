#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<=(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int a,b,c,x;
  cin >> a >> b >> c >> x;
  int ans=0;
  rep(i,a)rep(j,b)rep(k,c){
    if(x==i*500+j*100+k*50) ans++;
  }
  cout << ans << endl;
}