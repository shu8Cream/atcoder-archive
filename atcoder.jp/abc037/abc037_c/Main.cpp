/**
*    author:  shu8Cream
*    created: 17.12.2020 20:01:34
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;

int main() {
    int n,k;
    cin >> n >> k;
    vi a(n);
    rep(i,n) cin >> a[i];
    ll ans = 0;
    rep(i,n-k+1)rep(j,k) ans+=a[i+j];
    cout << ans << endl;
}