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
  int n;
  cin >> n;
  vi a(n+2);
  int sum=0,ans=0;
  a[0]=0; a[n+1]=0;
  rep(i,n) cin >> a[i+1];
  rep(i,n+1) sum+=abs(a[i]-a[i+1]);
  rep(i,n){
    ans=sum-abs(a[i]-a[i+1])-abs(a[i+1]-a[i+2])+abs(a[i]-a[i+2]);
  	cout << ans << endl;
  }
}