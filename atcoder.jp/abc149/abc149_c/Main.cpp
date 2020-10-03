#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int x;
  cin >> x;
  int MAX = 1000000, times = 0;
  for (int i = 2; i <= MAX; i++) {
    bool isPrime = true;
    for (int j = 2; j <= sqrt(i); j++) {
      times++;
      if (i % j == 0) {
        isPrime = false;
        break;
      }
    }
    if (isPrime && x<=i) {
      cout << i << endl;
      return 0;
    }
  }
}