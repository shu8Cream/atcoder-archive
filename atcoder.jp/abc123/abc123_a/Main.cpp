#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  vi a(5);
  rep(i,5) cin >> a[i];
  int k;
  cin >> k;
  bool f=1;
  rep(i,5){
    for(int j=i+1; j<5; j++) if(abs(a[j]-a[i])>k) f=0;
  }
  if(f) cout << "Yay!" << endl;
  else cout << ":(" << endl;
}