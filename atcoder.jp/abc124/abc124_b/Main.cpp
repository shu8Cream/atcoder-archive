#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n;
  cin >> n;
  int mxh=0,ans=0;
  rep(i,n){
    int h;
    cin >> h;
    mxh=max(mxh, h);
    if(mxh==h) ans++;
  }
  cout << ans << endl;
}