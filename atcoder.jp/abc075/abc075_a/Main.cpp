#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;

int main(){
  int A,B,C;
  cin >> A >> B >> C;
  if(A==B){
    cout << C << endl;
  }else if(B==C){
    cout << A << endl;
  }else{
    cout << B << endl;
  }
}