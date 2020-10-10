#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int h,w;
  cin >> h >> w;
  string a[110];
  rep(i,h) cin >> a[i];
  vector<bool> row(110), col(110);
  rep(i,h)rep(j,w){
    if(a[i][j]=='#'){
      row[i]=true;
      col[j]=true;
    }
  }
  rep(i,h){
    if(row[i]){
      rep(j,w){
        if(col[j]) cout << a[i][j];
      }
      cout << endl;
    }
  }
}