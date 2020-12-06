#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;

int main(){
  int n;
  cin >> n;
  vi a(n),b(n);
  rep(i,n) cin >> a[i];
  rep(i,n) b[i]=abs(a[i]-i-1);
  int sum=0;
  bool f=0;
  rep(i,n){
    sum+=b[i];
    if(b[i]==0) f=1;
  }
  int k=0,l=0;
  if(sum!=(n-1)*2 || f){
    cout << -1 << endl;
    return 0;
  }else{
    rep(i,n){
      l=k;
      if(a[i]==k+1) k=i;
      for(int j=k; j>=l+1; j--) cout << j << endl;
    }
  }
}