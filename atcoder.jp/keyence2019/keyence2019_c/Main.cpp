#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];
  ll s=0,t=0,cnt=0,cnt1=0,sum=0;
  rep(i,n){
    if(a[i]>b[i]){
      s+=a[i]-b[i];
      c[i]=a[i]-b[i];
    }
    if(a[i]<b[i]){
      t+=b[i]-a[i];
      cnt++;
    }
  }
  sort(c.begin(), c.end());
  reverse(c.begin(), c.end());
  if(s<t){
    cout << -1 << endl;
    return 0;
  }
  rep(i,n){
    sum+=c[i];
    cnt1++;
    if(sum>=t) break;
  }
  if(cnt==0) cout << 0 << endl;
  else cout << cnt+cnt1 << endl;
}