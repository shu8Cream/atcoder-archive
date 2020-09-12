#include <bits/stdc++.h>
#define rep(i,n) for (ll i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main(){
  ll N,D;
  cin >> N >> D;
  vector<P> a(N);
  rep(i,N){
    ll x,y;
	cin >> x >> y;
    a.at(i)=make_pair(x,y);
  }
  int cnt=0;
  rep(i,N){
    ll x,y;
    tie(x,y)=a.at(i);
	if(D*D>=x*x+y*y)
      cnt++;
  }
  cout << cnt <<endl;
}