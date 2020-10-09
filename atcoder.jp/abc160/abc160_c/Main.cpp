#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int k,n;
  cin >> k >> n;
  vector<int> a(2*n);
  rep(i,n) cin >> a[i];
  rep(i,n) a[i+n]=a[i]+k;
  int ans=k;
  rep(i,n){
    int sum=a[n-1+i]-a[i];
    ans=min(ans,sum);
  }
  cout << ans << endl;
}