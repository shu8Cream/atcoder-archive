#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int A, B;
  cin >> A >> B;
  int cnt=0,m=1;
  while(m<B){
    m+=A-1;
  	cnt++;
  }
  
  
  cout << cnt << endl;
}