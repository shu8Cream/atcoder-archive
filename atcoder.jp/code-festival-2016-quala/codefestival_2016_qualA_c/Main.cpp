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
  string s;
  cin >> s;
  int k;
  cin >> k;
  rep(i,s.size()){
    if(s[i]=='a' || 'z'-s[i]+1>k) continue;
    else{
      k-='z'-s[i]+1;
      s[i]='a';
    }
  }
  if(k!=0) s.back()='a'+(s.back()-'a'+k)%26;
  cout << s << endl;
}