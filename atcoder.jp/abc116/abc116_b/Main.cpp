#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;

int main(){
  int s;
  cin >> s;
  vi a;
  a.push_back(s);
  for(int i=1; i<=1000000; i++){
    if(a[i-1]%2==0) a.push_back(a[i-1]/2);
    else a.push_back(3*a[i-1]+1);
  }
  int ans=0;
  bool f=false;
  rep(i,a.size()){
    if(f && a[i]==4){
      ans=i+1;
      break;
    }
    if(a[i]==4) f=true;
  }
  if(s==2 || s==1) cout << 4 << endl;
  else cout << ans << endl;
}