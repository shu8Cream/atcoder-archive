#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  ll n;
  cin >> n;
  vector<vector<int>> a(2, vector<int>(n));
  rep(i,2)rep(j,n) cin >> a[i][j];
  vector<vector<int>> b(2, vector<int>(n));
  rep(i,2)rep(j,n){
    if(i==0){
      if(j-1<0) b[i][j]=a[i][j];
      else b[i][j]=b[i][j-1]+a[i][j];
    }else{
      if(j-1<0) b[i][j]=b[i-1][j]+a[i][j];
      else b[i][j]=max(b[i-1][j]+a[i][j], b[i][j-1]+a[i][j]);
    }
  }
  
  cout << b[1][n-1] << endl;
}