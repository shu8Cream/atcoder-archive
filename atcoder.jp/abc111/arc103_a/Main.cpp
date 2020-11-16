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
  int n;
  cin >> n;
  vi v(n);
  rep(i,n) cin >> v[i];
  vi a(100010), b(100010);
  rep(i,n){
	if(i%2==0) a[v[i]]++;
    else b[v[i]]++;
  }
  int maxa,maxb;
  maxa = max_element(a.begin(), a.end()) - a.begin();
  maxb = max_element(b.begin(), b.end()) - b.begin();
  
  if(maxa != maxb) cout << (n/2-a[maxa]) + (n/2-b[maxb]) << endl;
  else{
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    cout << min((n/2-a[0]) + (n/2-b[1]), (n/2-a[1]) + (n/2-b[0])) << endl;
  }
}