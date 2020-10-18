#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  vector<ll> a(n), b(n+1);
  rep(i,n) cin >> a[i];
  sort(a.rbegin(), a.rend());
  ll sum=0;
  int t=n-1;
  rep(i,n){
    int lim=2;
    if(i==0) lim=1;
    rep(j,lim){
      if(t>0){
      	sum+=a[i];
        t--;
      }
    }
  }
  cout << sum << endl;
}