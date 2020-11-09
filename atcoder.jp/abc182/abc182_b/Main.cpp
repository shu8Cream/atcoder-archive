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
  vi a(n);
  rep(i,n) cin >> a[i];
  int ans=0, mcnt=0;
  for(int i=2; i<1001; i++){
    int cnt=0;
    rep(j,n){
      if(a[j]%i==0) cnt++;
    }
    mcnt=max(mcnt, cnt);
    if(mcnt==cnt) ans=i;
  }
  cout << ans << endl;
}