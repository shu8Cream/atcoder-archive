#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin>>n;
  if(n%10==3){
    cout<<"bon"<<endl;
    return 0;
  }
  if(n%10==0 || n%10==1 || n%10==6 || n%10==8){
    cout<<"pon"<<endl;
    return 0;
  }
  cout << "hon" << endl;
}