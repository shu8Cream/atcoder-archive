#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;

int main(){
  int n;
  cin >> n;
  vi a(n);
  rep(i,n) cin >> a[i];
  deque<int> d;
  rep(i,n){
    if(i%2==0) d.push_back(a[i]);
    else d.push_front(a[i]);
  }
  if(n%2==0) rep(i,n) cout << d[i] << endl;
  else for(int i=n-1; i>=0; i--) cout << d[i] << endl;
}