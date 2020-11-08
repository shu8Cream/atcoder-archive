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
  string n;
  cin >> n;
  int sum=0;
  rep(i,n.size()){
    sum+=n[i]-'0';
  }
  int ans=3,sumt=sum;
  if(sum%3==0) ans=0;
  else{
    int i=0;
    rep(i,n.size()){
      sumt=sum;
      sumt-=n[i];
      if(sumt%3==0) ans=min(ans, 1);
      rep(j,n.size()){
        if(i==j) continue;
        sumt-=n[j];
        if(sumt%3==0) ans=min(ans, 2);
      }
    }
  }
  if(n.size()==ans) cout << -1 << endl;
  else cout << ans << endl;
}