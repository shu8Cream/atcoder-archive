#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  int t=0;
  while(a>0 && c>0){
    if(t%2==0) c-=b;
    else a-=d;
    t++;
  }
  if(a>0) cout << "Yes" << endl;
  else cout << "No" << endl;
}