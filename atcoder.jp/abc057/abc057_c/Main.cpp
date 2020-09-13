#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int cnt_digits(ll N){ 
  int digits=0;
  while(N>0){
    N/=10;
    digits++;
  }
  return digits;
}
                     
int main(){
  ll N;
  cin >> N;
  int ans=cnt_digits(N);
  for(ll A=1LL;A*A<=N;++A){
    if(N%A!=0) continue;
    const ll B=N/A;
    const int cur=max(cnt_digits(A),cnt_digits(B));
    if(ans>cur){
      ans=cur;
    } 
  }
  cout << ans << endl;
}