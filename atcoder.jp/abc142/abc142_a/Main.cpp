#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  int cnt=0;
  for(int i=1; i<n+1; i++){
    if(i%2==1) cnt++;
  }
  cout << (double)cnt/n << endl;
}