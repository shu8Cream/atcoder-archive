#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int K, S;
  cin >> K >> S;
  int cnt=0;
  for(int i=0;i<K+1;i++){
    for(int j=0;j<K+1;j++){
      if(S-(i+j)<K+1 && S-(i+j)>-1){
        cnt++;
      }
    }
  }
  cout << cnt << endl;
}