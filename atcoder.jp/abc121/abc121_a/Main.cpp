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
  int h,w,h1,w1;
  cin >> h >> w >> h1 >> w1;
  int ans=h*w-h1*w-w1*h+h1*w1;
  cout << ans << endl;
}