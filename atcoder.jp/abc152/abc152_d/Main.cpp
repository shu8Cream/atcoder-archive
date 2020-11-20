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
  int n;
  cin >> n;
  vvi cnt(9, vi(9));
  for(int i=1; i<=n; i++){
    string s = to_string(i);
    if(s[s.size()-1]=='0') continue;
    int a = s[0] - '0';
    int b = s[s.size()-1] - '0';
    cnt[a-1][b-1]++;
  }
  ll ans=0;
  rep(i,9) ans+=cnt[i][i]+cnt[i][i]*(cnt[i][i]-1);
  rep(i,9){
    for(int j=i+1; j<9; j++){
      ans+=cnt[i][j]*cnt[j][i]*2;
    }
  }
  cout << ans << endl;
}