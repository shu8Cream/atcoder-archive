#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int c[3][3];

int main(){
  rep(i,3)rep(j,3) cin >> c[i][j];
  int b1=0,b2=0,b3=0;
  rep(a1,100){
    b1=c[0][0]-a1;
    b2=c[0][1]-a1;
    b3=c[0][2]-a1;
    bool fl=0;
    if(c[1][0]-b1==c[1][1]-b2 && c[1][1]-b2==c[1][2]-b3) fl=1;
    if(fl && c[2][0]-b1==c[2][1]-b2 && c[2][1]-b2==c[2][2]-b3){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}