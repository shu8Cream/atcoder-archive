#include <bits/stdc++.h>
using namespace std;

int main() {
  int p;
  cin >> p;

  // パターン1
  int price;
  if (p == 1) {
    cin >> price;
  }

  // パターン2
  if (p == 2) {
    string text;
    cin >> text >> price;
    cout << text << "!" << endl;
  }

  int N;
  cin >> N;

  //cout << text << "!" << endl;
  cout << price * N << endl;
}
