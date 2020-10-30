#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using mint = modint1000000007;

int main(){
  ll n,k;
  cin >> n >> k;
  vi a(n), b(2*n);
  rep(i,n) cin >> a[i], b[i]=a[i], b[i+n]=a[i];
  mint ans=0, l=0;
  rep(i,n){
    rep(j,n){
      if(a[i]<a[j]){
        ans++;
        if(i>j) l++;
      }
    }
  }
  mint kc=(ll)k*(k-1)/2;
  ans=(mint)l*k+(mint)ans*kc;
  cout << ans.val() << endl;
}