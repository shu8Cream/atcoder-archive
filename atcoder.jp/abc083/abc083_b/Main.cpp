#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n,a,b;
  cin >> n >> a >> b;
  int ans=0;
  rep(i,n){
    int x=i+1,sum=0;
    while(x!=0){
      sum=sum+x%10;
      x/=10;
    }
    if(a<=sum && sum<=b) ans+=(i+1);
  }
  cout << ans << endl;
}