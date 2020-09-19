#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  vector<vector<int>> d(n, vector<int>(2));
  rep(i,n)rep(j,2) cin >> d[i][j];
  rep(i,n-2){
    if(d[i][0]==d[i][1]&&d[i+1][0]==d[i+1][1]&&d[i+2][0]==d[i+2][1]){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}