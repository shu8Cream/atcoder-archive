#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n,k;
  cin>>n>>k;
  vector<int> p(n);
  rep(i,n) cin>>p[i];
  int ans=0;
  sort(p.begin(),p.end());
  rep(i,k) ans+=p[i];
  cout << ans << endl;
}