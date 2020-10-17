#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n,k,q;
  cin >> n >> k >> q;
  vector<int> a(q), b(n,k-q);
  rep(i,q) cin >> a[i];
  rep(i,q) b[a[i]-1]++;
  rep(i,n){
    if(b[i]<=0) cout << "No" << endl;
    else cout << "Yes" << endl;
  }
}