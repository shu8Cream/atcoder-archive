#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n,m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i,n) cin>>a[i];
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  int sum=0;
  rep(i,n) sum+=a[i];
  if(a[m-1]*4*m>=sum) cout << "Yes" << endl;
  else cout << "No" << endl;
}