#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

string divide[4] = {"dream","dreamer","erase","eraser"};

int main(){
  string s;
  cin>>s;
  reverse(s.begin(),s.end());
  rep(i,4) reverse(divide[i].begin(),divide[i].end());
  int f1=1;
  for(int i=0;i<s.size();){
    int f2=0;
    rep(j,4){
      string d = divide[j];
      if(s.substr(i,d.size())==d){
        i+=d.size();
        f2=1;
      }
  	}
    if(1-f2){
      f1=0;
      break;
    }
  }
  if(f1) cout << "YES" << endl;
  else cout << "NO" << endl;
}