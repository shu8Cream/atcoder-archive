/**
*    author:  shu8Cream
*    created: 07.05.2021 21:06:26
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,k;
    cin >> n >> k;
    vi a(n); ll M = 0, g = 0;
    rep(i,n){
        cin >> a[i];
        M = max(M,a[i]);
        g = gcd(g,a[i]);
    }
    bool ok = false;
    if(k%g==0 && M>=k) ok = true;
    cout << (ok ? "POSSIBLE" : "IMPOSSIBLE") << endl;
}