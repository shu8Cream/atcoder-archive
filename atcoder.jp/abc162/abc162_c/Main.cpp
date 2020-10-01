#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int gcd(int a, int b, int c){
  while (b > 0) {
    int r = a % b;
    a = b;
    b = r;
  }
  while (c > 0) {
    int r = a % c;
    a = c;
    c = r;
  }
  return a;
}

int main(){
  int k;
  cin >> k;
  int sum=0;
  for(int i=1; i<=k; i++){
    for(int j=1; j<=k; j++){
      for(int l=1; l<=k; l++){
        sum+=gcd(i,j,l);
      }
    }
  }
  cout << sum << endl;
}