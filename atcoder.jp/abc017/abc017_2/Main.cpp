#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  string x;
  cin >> x;
  rep(i,x.size()){
    if(x[i]=='c'&&x[i+1]=='h'){
      i++;
      continue;
    }
    else if(x[i]=='k') continue;
    else if(x[i]=='o') continue;
    else if(x[i]=='u') continue;
    else{
      cout << "NO" <<endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}