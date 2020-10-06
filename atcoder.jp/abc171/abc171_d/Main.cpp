#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  ll n,q,a;
  ll sum=0;
  cin >> n;
  vector<int> av(1e5+1,0);
  rep(i,n){
    cin >> a;
    av[a]++;
  }
  rep(i,1e5+1){
    sum+=av[i]*i;
  }
  cin >> q;
  rep(i,q){
    ll b,c;
    cin >> b >> c;
    sum-=b*av[b];
    av[c]+=av[b];
    sum+=c*av[b];
    av[b]=0;
    cout << sum << endl;
  }
}