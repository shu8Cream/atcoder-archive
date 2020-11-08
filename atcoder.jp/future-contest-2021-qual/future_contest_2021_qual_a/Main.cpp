#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i=0; i<(n); i++)

int main(){
  int xp=0, yp=0;
  rep(i,100){
    int x,y;
    cin >> x >> y;
    if(y-yp>0){
      rep(i,y-yp) cout << 'R';
      //cout << 'I';
    }
    if(y-yp<0){
      rep(i,yp-y) cout << 'L';
      //cout << 'I';
    }
    if(x-xp>0){
      rep(i,x-xp) cout << 'D';
      //cout << 'I';
    }
    if(x-xp<0){
      rep(i,xp-x) cout << 'U';
      //cout << 'I';
    }
    cout << 'I';
    xp=x;
    yp=y;
  }
}