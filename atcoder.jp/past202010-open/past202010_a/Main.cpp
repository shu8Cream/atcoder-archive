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
  int a,b,c;
  cin >> a >> b >> c;
  if((b<a && a<c) || (c<=a && a<=b)) cout << "A" << endl;
  else if((a<b && b<c) || (c<=b && b<=a)) cout << "B" << endl;
  else if((b<c && c<a) || (a<=c && c<=b)) cout << "C" << endl;
} 