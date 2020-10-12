#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  set<int> a;
  rep(i,n){
    int b;
    cin >> b;
    if(a.count(b)){
      cout << "NO" << endl;
      return 0;
    }else{
      a.insert(b);
    }
  }
  cout << "YES" << endl;
}