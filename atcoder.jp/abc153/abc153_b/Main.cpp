#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int h,n;
  cin >> h >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  int ans=0;
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  rep(i,n){
    h-=a[i];
    if(h<=0){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}