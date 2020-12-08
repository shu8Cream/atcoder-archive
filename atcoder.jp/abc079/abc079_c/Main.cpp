#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;

int main(){
  string s;
  cin >> s;
  int n=s.size();
  int sum=s[0]-'0';
  rep(b,1<<(n-1)){
    sum=s[0]-'0';
    rep(i,n-1){
      if(b>>i&1) sum+=s[i+1]-'0';
      else sum-=s[i+1]-'0';
    }
    if(sum==7){
      rep(i,n-1){
        cout << s[i];
        if(b>>i&1) cout << "+";
        else cout << "-";
      }
      cout << s[n-1] << "=7" << endl;
      return 0;
    }
  }
}