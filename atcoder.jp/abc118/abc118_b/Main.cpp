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
  int n,m;
  cin >> n >> m;
  vi cnt(m);
  rep(i,n){
    int k;
    cin >> k;
    rep(j,k){
      int a;
      cin >> a;
      a--;
      cnt[a]++;
    }
  }
  int ans=0;
  rep(i,m) if(cnt[i]==n) ans++;
  cout << ans << endl;
}