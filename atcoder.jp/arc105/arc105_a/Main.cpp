#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  if(a==b+c+d){
    cout << "Yes" << endl;
    return 0;
  }
  if(b==a+c+d){
    cout << "Yes" << endl;
    return 0;
  }
  if(c==b+a+d){
    cout << "Yes" << endl;
    return 0;
  }
  if(d==b+c+a){
    cout << "Yes" << endl;
    return 0;
  }
  if(a+b==c+d){
    cout << "Yes" << endl;
    return 0;
  }
  if(a+c==b+d){
    cout << "Yes" << endl;
    return 0;
  }
  if(a+d==c+b){
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
}