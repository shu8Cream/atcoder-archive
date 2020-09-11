#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int N;
  cin >> N;
  for(int X=0;X<N+1;X++){
    int a=X*1.08;
    if(N==a){
	  cout << X << endl;
      return 0;
    }
  }
  cout << ":(" << endl;
}