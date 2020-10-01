#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i,n) cin >> s[i];
  set<string> a;
  rep(i,n) a.insert(s[i]);
  cout << a.size() << endl;
}