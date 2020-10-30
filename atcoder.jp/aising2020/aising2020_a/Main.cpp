#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int l,r,d;
  cin >> l >> r >> d;
  int cnt=0;
  for(int i=l; i<=r ;i++){
    if(i%d==0) cnt++;
  }
  cout << cnt << endl;
}