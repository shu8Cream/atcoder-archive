#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const vector<string> w = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

int main(){
  string s;
  cin >> s;
  int ans=0;
  rep(i,7){
    if(s==w[i]) ans=7-i;
  }
  cout << ans << endl;
}