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

ll atk(ll h){
  if(h==1){
    return 1;
  }else{
    return 2*atk(h/2)+1;
  }
}

int main(){
  ll h;
  cin >> h;
  ll ans=atk(h);
  cout << ans << endl;
}