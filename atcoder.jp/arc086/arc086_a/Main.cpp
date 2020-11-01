#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using mint = modint998244353;
//using mint = modint1000000007;

int main(){
  int n,k;
  cin >> n >> k;
  vi b(n);
  rep(i,n){
    int a;
    cin >> a;
    b[a-1]++;
  }
  sort(b.rbegin(), b.rend());
  int ans=n;
  rep(i,k){
    ans-=b[i];
  }
  cout << max(ans, 0) << endl;
}