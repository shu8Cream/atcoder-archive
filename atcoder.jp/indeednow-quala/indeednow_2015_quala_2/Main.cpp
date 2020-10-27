#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  string key = "indeednow";
  sort(key.begin(), key.end());
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i,n){
    cin >> s[i];
    sort(s[i].begin(), s[i].end());
  }
  rep(i,n){
    if(key==s[i]) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}