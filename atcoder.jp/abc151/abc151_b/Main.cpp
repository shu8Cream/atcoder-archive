#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n,k,m;
  cin >> n >> k >> m;
  int sum=0,a;
  rep(i,n-1){
    cin >> a;
    sum+=a;
  }
  if(m*n-sum <= k && m*n-sum >= 0) cout << m*n-sum << endl;
  else if(m*n-sum <= k && m*n-sum < 0) cout << 0 << endl;
  else cout << -1 << endl;
}