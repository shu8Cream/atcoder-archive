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
  int n,x;
  cin >> n >> x;
  vi m(n);
  rep(i,n) cin >> m[i];
  int sum=0,ans=0;
  rep(i,n) sum+=m[i];
  x-=sum;
  sort(m.begin(), m.end());
  cout << x/m[0]+n << endl;
}