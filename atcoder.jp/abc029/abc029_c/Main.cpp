#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

string f(int n){
  if(n==0) return "";
  n--;
  return f(n/3) + string(1, 'a'+n%3);
}

int main(){
  int n;
  cin >> n;
  vi a(n+1);
  rep(i,n) a[i+1]=pow(3,i+1)+a[i];
  for(int i=a[n-1]; i<a[n]; i++) cout << f(i+1) << endl;
}