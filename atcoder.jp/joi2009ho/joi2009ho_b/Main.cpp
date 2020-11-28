#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;

int main(){
  int D,n,m;
  cin >> D >> n >> m;
  vi d(n+1),k(m);
  rep(i,n-1) cin >> d[i+1]; //ピザ屋の位置
  d[n]=D;
  sort(d.begin(), d.end());
  rep(i,m) cin >> k[i]; //宅配先
  int ans=0;
  rep(i,m){
    auto itr = lower_bound(d.begin(), d.end(), k[i]);
    ans+=min(abs(*itr-k[i]), abs(*(itr-1)-k[i]));
  }
  cout << ans << endl;
}