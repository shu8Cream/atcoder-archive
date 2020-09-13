#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin>>n;
  int cnt=2,ans=0;
  for(int i=1;i<n+1;i+=2){
    for(int j=3;j<i;j+=2){
      if(i%j==0) cnt++;
    }
    if(cnt==8) ans++;
    cnt=2;
  }
  cout << ans << endl;
}