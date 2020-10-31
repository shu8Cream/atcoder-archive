#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
//using mint = modint1000000007;

int main(){
  int n;
  cin >> n;
  vi p(n);
  rep(i,n) cin >> p[i];
  int cnt=0;
  for(int i=1; i<n-1; i++){
    if(p[i-1]<=p[i] && p[i]<=p[i+1]) cnt++;
    if(p[i-1]>=p[i] && p[i]>=p[i+1]) cnt++;
  }
  cout << cnt << endl;
}