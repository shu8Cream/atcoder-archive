#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main(){
  int n,m;
  cin >> n >> m;
  vector<P> a(n);
  rep(i,n) cin >> a[i].first >> a[i].second;
  sort(a.begin(), a.end());
  ll ans=0;
  rep(i,n){
    if(a[i].second>=m){
      ans+=m*a[i].first;
      m=0;
    }else{
      m-=a[i].second;
      ans+=a[i].first*a[i].second;
    }
    if(m<=0) break;
  }
  cout << ans << endl;
}