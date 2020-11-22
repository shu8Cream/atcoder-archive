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

vector<ll> divisor(ll n) {
    vector<ll> ret;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end()); // 昇順に並べる
    return ret;
}

int main(){
  ll s,p;
  cin >> s >> p;
  bool f=0;
  vector<ll> a = divisor(p);
  rep(i,a.size()){
    if(s-a[i]>0 && p==(s-a[i])*a[i]) f=1;
  }
  if(f) cout << "Yes" << endl;
  else cout << "No" << endl;
}