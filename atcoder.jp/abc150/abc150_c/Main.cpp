#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  vector<int> p(n), q(n), r(n);
  rep(i,n) cin >> p[i];
  rep(i,n) cin >> q[i];
  rep(i,n) r[i]=i+1;
  int a=0,b=0,cnt=1;
  do {
    int c2=0,c3=0;
    rep(i,n) {
      if(r[i]==p[i]) c2++;
    }
    if(c2==n) a=cnt;
    rep(i,n) {
      if(r[i]==q[i]) c3++;
    }
    if(c3==n) b=cnt;
    cnt++;
  } while (next_permutation(r.begin(), r.end()));

  cout << abs(a-b) << endl;
}