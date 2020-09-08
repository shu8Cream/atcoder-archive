#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A;
  cin >> N >> A;

  // ここにプログラムを追記
  for(int i=0; i<N; i++){
    string op;
    int B, C; 
    cin >> op >> B;
    if(op=="+"){
      A+=B;
      cout << i+1 << ":" << A <<endl;
    }
    if(op=="-"){
      A-=B;
      cout << i+1 << ":" << A <<endl;
    }
    if(op=="*"){
      A*=B;
      cout << i+1 << ":" << A <<endl;
    }
    if(op=="/"){
      if(B==0){
        cout << "error" << endl;
        break;
      }else{
        A/=B;
        cout << i+1 << ":" << A <<endl;
      }
    }
  }
}
