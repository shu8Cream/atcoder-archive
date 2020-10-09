#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  string s;
  ll k;
  cin >> s >> k;
  rep(i,s.size()){
    if(s[i]!='1'){
      cout << s[i] <<endl;
      return 0;
    }else{
      if(i+1>=k){
        cout << 1 << endl;
        return 0;
      }
    }
  }
}