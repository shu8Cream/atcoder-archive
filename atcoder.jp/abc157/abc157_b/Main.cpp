#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  vector<vector<int>> a(3, vector<int>(3));
  rep(i,3)rep(j,3) cin >> a[i][j];
  int n;
  cin >> n;
  vector<int> b(n);
  rep(i,n) cin >> b[i];
  rep(i,3)rep(j,3){
    rep(k,n){
      if(a[i][j]==b[k]) a[i][j]=0;
    }
  }
  rep(i,3){
    if(a[i][0]+a[i][1]+a[i][2]==0){
      cout << "Yes" << endl;
      return 0;
    }
  }
  rep(i,3){
    if(a[0][i]+a[1][i]+a[2][i]==0){
      cout << "Yes" << endl;
      return 0;
    }
  }
  if(a[0][0]+a[1][1]+a[2][2]==0 || a[0][2]+a[1][1]+a[2][0]==0){
      cout << "Yes" << endl;
      return 0;
  }
  cout << "No" << endl;
}