#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n,k;
  cin >> n >> k;
  int cnt=0;
  while(n>=k){
    n/=k;
    cnt++;
  }
  if(n!=0) cnt++;
  cout << cnt << endl;
}