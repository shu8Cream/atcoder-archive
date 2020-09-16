#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n,k;
  cin>>n>>k;
  vector<int> d(k);
  vector<vector<int>> a(k, vector<int>(n));
  rep(i,k){
    cin>>d[i];
    rep(j,d[i]) cin>>a[i][j];
  }
  int ans=n;
  for(int l=1; l<=n; l++){
    bool have = false;
    rep(i,k)rep(j,n){
      if(l==a[i][j]) have = true;
    }
    if(have) ans--;
  }
  cout << ans << endl;
}