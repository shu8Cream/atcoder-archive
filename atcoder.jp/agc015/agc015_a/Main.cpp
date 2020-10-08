#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  ll n,a,b;
  cin >> n >> a >> b;
  ll cnt=0;
  if(n==1 && a==b) cnt=1;
  else if(n==1 || a>b) cnt=0;
  else {
    cnt=(b-a)*(n-2)+1;
  }
  cout << cnt << endl;
}