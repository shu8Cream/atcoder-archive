#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
//using mint = modint1000000007;

const vi a = {100, 101, 102, 103, 104, 105};

int main(){
  int x;
  cin >> x;
  bool f=0;
  for(int i=1; i<x; i++){
    if(i*100<=x && x<=i*105) f=1;
  }
  cout << f << endl;
}