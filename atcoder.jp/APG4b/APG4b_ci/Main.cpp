#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  int min1 = min(A,B);
  min1 = min(min1, C);
  int max1 = max(A,B);
  max1 = max(max1, C);
  cout << max1-min1 << endl;
}