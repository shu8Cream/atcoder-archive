#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n,m;
  cin >> n >> m;
  vector<int> h(n);
  vector<int> ma(n);
  rep(i,n) cin >> h[i];
  rep(i,m){
    int a,b;
    cin >> a >> b;
    ma[a-1]=max(ma[a-1], h[b-1]);
    ma[b-1]=max(ma[b-1], h[a-1]);
  }
  int cnt=0;
  rep(i,n){
    cnt+=h[i]>ma[i];
  }
    
  cout << cnt <<endl;
}