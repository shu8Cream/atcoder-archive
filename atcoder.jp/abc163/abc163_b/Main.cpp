#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n,m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i,m) cin >> a[i];
  int sum=0;
  rep(i,m) sum+=a[i];
  if(sum>n) cout << -1 << endl;
  else cout << n-sum << endl;
}