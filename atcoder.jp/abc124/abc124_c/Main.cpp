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
  string s;
  cin >> s;
  int ans=0, cnt1=0, cnt2=0;
  rep(i,s.size()){
    if(i%2==0 && s[i]!='1') cnt1++;
    if(i%2==1 && s[i]!='0') cnt1++;
    if(i%2==0 && s[i]!='0') cnt2++;
    if(i%2==1 && s[i]!='1') cnt2++;
    ans=min(cnt1, cnt2);
  }
  cout << ans << endl;
}