#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n,t;
  cin >> n >> t;
  vector<ll> s(n);
  rep(i,n) cin >> s[i];
  ll sum=0;
  rep(i,n-1){
    if(s[i+1]-s[i]>t) sum+=t;
    if(s[i+1]-s[i]<=t) sum+=s[i+1]-s[i];
  }
  sum+=t;
  cout << sum << endl;
}