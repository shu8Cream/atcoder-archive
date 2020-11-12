#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n;
  cin >> n;
  vector<pair<pair<string, int>, int>> a(n);
  rep(i,n){
    string s; int p;
    cin >> s >> p;
    a[i].first.first = s;
    a[i].first.second = -p;
    a[i].second = i+1;
  }
  sort(a.begin(), a.end());
  rep(i,n) cout << a[i].second << endl;
}