#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;

int op(int a, int b){
  return a^b;
}

int e(){return 0;}

int main(){
  int n,q;
  cin >> n >> q;
  segtree<int, op, e> seg(n);
  rep(i,n){
    int a;
    cin >> a;
    seg.set(i,a);
  }
  
  rep(i,q){
    int t,x,y;
    cin >> t >> x >> y;
    --x;
    if(t==1) seg.set(x,seg.get(x)^y);
    if(t==2){
      int ans = seg.prod(x,y);
      cout << ans << endl;
    }
  }
}