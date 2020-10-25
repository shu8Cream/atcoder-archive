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
  int n;
  cin >> n;
  vi h(n);
  rep(i,n) cin >> h[i];
  bool down=false;
  int tmpMax=h[0]-1;
  rep(i,n){
    if(tmpMax>h[i]) down=true;
    else tmpMax=max(tmpMax, h[i]-1);
  }
  if(down) cout << "No" << endl;
  else cout << "Yes" << endl;
}