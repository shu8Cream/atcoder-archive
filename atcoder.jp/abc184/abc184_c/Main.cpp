#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;

int main(){
  ll r1,c1,r2,c2;
  cin >> r1 >> c1 >> r2 >> c2;
  ll x1 = r1 + c1;
  ll y1 = r1 - c1;
  ll x2 = r2 + c2;
  ll y2 = r2 - c2;
  int ans;
  if(x1==x2 && y1==y2){
    cout << 0 << endl;
    return 0;
  }else if(abs(x1-x2)<=3 && abs(y1-y2)<=3){
    cout << 1 << endl;
    return 0;
  }else if(x1==x2 || y1==y2){
    cout << 1 << endl;
    return 0;
  }else if(abs(x1-x2)<=3 || abs(y1-y2)<=3){
    cout << 2 << endl;
    return 0;
  }else if(abs(x1-x2)%2==0){
    cout << 2 << endl;
    return 0;
  }else if(max(abs(x1-x2), abs(y1-y2)) <= 6){
    cout << 2 << endl;
    return 0;
  }else{
    cout << 3 << endl;
    return 0;
  }
}