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
  ll n,w;
  cin >> n >> w;
  vector<ll> s(n),t(n),p(n);
  rep(i,n){
    cin >> s[i] >> t[i] >> p[i];
  }
  ll tmax=0;
  rep(i,n) tmax=max(tmax,t[i]);
  vector<ll> table(tmax+5);
  rep(i,tmax+5) table[i]=0;
  rep(i,n){
    table[s[i]]+=p[i];
    table[t[i]]-=p[i];
  }
  rep(i,tmax+5){
    if(0<i) table[i]+=table[i-1];
  }
  rep(i,table.size()){
    if(w<table[i]){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}