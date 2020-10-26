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
  int n;
  cin >> n;
  vi p(n);
  rep(i,n) cin >> p[i];
  int cnt=0;
  rep(i,n){
    if(i+1!=p[i]) cnt++;
  }
  if(cnt<=2 ) cout << "YES" << endl;
  else cout << "NO" << endl;
}