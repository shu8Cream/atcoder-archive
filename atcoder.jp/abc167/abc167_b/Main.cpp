#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int a,b,c,k;
  cin>>a>>b>>c>>k;
  if(k<=a) cout << k << endl;
  else if(k<=a+b) cout << a << endl;
  else cout << a-(k-a-b) << endl;
}