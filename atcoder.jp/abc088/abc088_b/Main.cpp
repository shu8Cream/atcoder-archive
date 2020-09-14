#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  int ans=0;
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
  int x=0,y=0;
  rep(i,n){
    if(i%2==0) x+=a[i];
    else y+=a[i];
  }
  cout << x-y << endl;
}