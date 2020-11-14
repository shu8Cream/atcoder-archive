#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;

int main(){
  int n;
  cin >> n;
  vi a(n);
  int ans=0;
  rep(i,n){
    cin >> a[i];
    ans+=a[i]-1;
  }
  cout << ans << endl;
}