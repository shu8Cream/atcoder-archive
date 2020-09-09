#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, X, T;
  cin >> N >> X >> T;
  int i=0;
  while(N>X*i){
    i++;
  }
  cout << i*T << endl;
}