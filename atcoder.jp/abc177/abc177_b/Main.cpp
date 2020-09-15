#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  string s,t;
  cin>>s>>t;
  int ans=t.size();
  rep(i,s.size()-t.size()+1){
    int cnt=0;
    rep(j,t.size()){
      if(t[j]!=s[i+j]){
        cnt++;
      }
    }
    ans=min(ans,cnt);
  }
  cout << ans << endl;
}