#include <bits/stdc++.h>
using namespace std;

int main() {
  string N;
  cin >> N;
  int sum=0;
  for(int i=0;i<N.size();i++){
    if(N.at(i)=='1'){
      sum+=1;
    }
	if(N.at(i)=='2'){
      sum+=2;
    }
    if(N.at(i)=='3'){
      sum+=3;
    }
    if(N.at(i)=='4'){
      sum+=4;
    }
    if(N.at(i)=='5'){
      sum+=5;
    }
    if(N.at(i)=='6'){
      sum+=6;
    }
    if(N.at(i)=='7'){
      sum+=7;
    }
    if(N.at(i)=='8'){
      sum+=8;
    }
    if(N.at(i)=='9'){
      sum+=9;
    }
  }
  if(sum%9==0){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}

