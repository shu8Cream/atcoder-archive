#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin>>S;
  int cnt=0;
  for(int i=0;i<3;i++){
    if(S.at(1)=='R'){
      if(S.at(0)=='R' && S.at(2)=='R'){
      	cnt=3;
      }else if(S.at(0)=='R' || S.at(2)=='R'){
        cnt=2;
      }else{
        cnt=1;
      }
    }else if(S.at(0)=='R' || S.at(2)=='R'){
      cnt=1;
    }
  }
  cout << cnt << endl;
}
