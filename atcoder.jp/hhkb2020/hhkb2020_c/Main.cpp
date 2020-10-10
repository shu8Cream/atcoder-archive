#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  vector<int> p(n);
  rep(i,n) cin >> p[i];
  set<int> s;
  rep(i,2e5+1) s.insert(i);
  rep(i,n){
    s.erase(p[i]);
    cout << *begin(s) << endl;
  }
}