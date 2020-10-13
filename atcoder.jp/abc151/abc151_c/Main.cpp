#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n, m;
  cin >> n >> m;
  vector<int> p(m), cw(n+1,0), ca(n+1,0);
  vector<string> s(m);
  rep(i,m) cin >> p[i] >> s[i];
  rep(i,m){
    if(s[i]=="AC" && ca[p[i]]==0) ca[p[i]]++;
    if(s[i]=="WA" && ca[p[i]]==0) cw[p[i]]++;
  }
  int ac=0, wa=0;
  rep(i,n+2){
    if(ca[i]) ac++;
    wa += ca[i]*cw[i];
  }
  cout << ac << " " << wa << endl;
}