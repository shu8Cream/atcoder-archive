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
  vi a(3);
  rep(i,s.size()){
    a[s[i]-'a']++;
  }
  bool f=0;
  if(abs(a[0]-a[1])<2 && abs(a[2]-a[1])<2 &&abs(a[0]-a[2])<2) f=1;
  if(f) cout << "YES" << endl;
  else cout << "NO" << endl;
}