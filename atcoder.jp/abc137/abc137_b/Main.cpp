#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int k,x;
  cin >> k >> x;
  for(int i=x-k+1; i<=x+k-1; i++){
    cout << i << " ";
  }
}