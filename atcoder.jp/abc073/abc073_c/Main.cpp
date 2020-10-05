#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  set<int> b;
  rep(i,n){
    int a;
    cin >> a;
    if(!b.count(a)) b.insert(a);
    else b.erase(a);
  }
  cout << b.size() << endl;
}