#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;

int main(){
  int n,k;
  cin >> n >> k;
  vi a(n);
  rep(i,n) cin >> a[i];
  int ans=0;
  rep(i,n-k){
    int sum=0;
    for(int j=i; j<k+i; j++){
      sum+=a[j];
    }
    ans=max(ans, sum);
  }
  
  cout << ans << endl;
}