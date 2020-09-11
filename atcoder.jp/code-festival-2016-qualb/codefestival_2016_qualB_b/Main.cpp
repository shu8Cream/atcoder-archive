#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int N, A, B;
  cin >> N >> A >> B;
  string S;
  cin >> S;
  int p=0,j=0;
  for(int i=0; i<N; i++){
    if(S.at(i)=='a'){
      if(A+B>p){
  		cout << "Yes" << endl;
        p++;
      }else
        cout << "No" << endl;
    }else if(S.at(i)=='b'){
      if(A+B>p&&B>j){
        cout << "Yes" << endl;
        j++;
      	p++;
      }else
        cout << "No" << endl;
    }else{
      cout << "No" << endl;
    }
  }
}