#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int a,b,k;
  cin>>a>>b>>k;
  int ans=0;
  int c=min(a,b);
  vector<int> d;
  for(int i=1;i<c+1;i++){
    if(a%i==0 && b%i==0) d.push_back(i);
  }
  ans=d[d.size()-k];
  cout << ans << endl;
}