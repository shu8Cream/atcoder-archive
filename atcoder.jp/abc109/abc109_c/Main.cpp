/**
*    author:  shu8Cream
*    created: 13.12.2020 15:08:00
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
    int n,X;
    cin >> n >> X;
    vi x(n);
    rep(i,n) cin >> x[i];
    vi y(n);
    rep(i,n) y[i]=abs(X-x[i]);
    int ans=y[0];
    rep(i,n) ans=gcd(ans, y[i]);
    cout << ans << endl;
}