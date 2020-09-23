#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int h,a;
  cin >> h >> a;
  int cnt = 0;
  if(h%a==0) cout << h/a << endl;
  else if(h%a!=0) cout << h/a+1 <<endl;
}