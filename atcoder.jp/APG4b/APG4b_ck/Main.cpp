#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;

  // ここにプログラムを追記
  int a=1;
  int N = (S.size()-1)/2;
  for(int i=0;i<N;i++){
    char op=S.at(i*2+1);
    if(op=='+'){
      a++;
    }
    if(op=='-'){
      a--;
    }
  }
  cout << a << endl;
}