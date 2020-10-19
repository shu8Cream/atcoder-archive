#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  ll n,k;
  cin >> n >> k;
  vvi next(60, vi(n));
  rep(i,n) cin >> next[0][i], --next[0][i];
  rep(i,59)rep(j,n) next[i+1][j] = next[i][next[i][j]];
  int j=0;
  rep(i,60) if(k & (1LL<<i)) j=next[i][j];
  cout << j+1 << endl;
}