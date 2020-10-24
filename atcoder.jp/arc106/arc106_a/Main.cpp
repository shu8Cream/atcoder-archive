#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for (int i=1; i<(n); i++)
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  ll n;
  cin >> n;
  rep(i,39){
    rep(j,27){
      if(n==powl(3,i)+powl(5,j)){
        cout << i << " " << j <<endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
}