#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  string s;
  cin >> s;
  int n=s.size();
  vi a(2);
  rep(i,n){
    a[s[i]-'0']++;
  }
  cout << n-abs(a[0]-a[1]) << endl;
}