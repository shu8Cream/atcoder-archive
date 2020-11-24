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
  ll n,m;
  cin >> n >> m;
  ll ans1=0, ans2=0;
  if(n-m/2>=0){
    ans1+=m/2;
  	m-=m/2*2;
  }
  if(m/4>0) ans1+=m/4;
  if(m-2*n>=0){
    ans2+=n;
    m-=n*2;
  }
  if(m/4>0) ans2+=m/4;
  ans1=max(ans1, ans2);
  cout << ans1 << endl;
}