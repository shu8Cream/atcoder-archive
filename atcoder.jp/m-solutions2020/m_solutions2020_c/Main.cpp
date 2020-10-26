#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n,k;
  cin >> n >> k;
  vi a(n);
  rep(i,n) cin >> a[i];
  //ll pScore=1, nScore=1;
  //rep(i,k) pScore*=a[i];
  rep(i,n-k){
    //nScore=pScore/a[i]*a[k+i];
    if(a[i]<a[k+i]) cout << "Yes" << endl;
    else cout << "No" << endl;
    //pScore=nScore;
  }
}