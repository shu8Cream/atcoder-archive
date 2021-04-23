/**
*    author:  shu8Cream
*    created: 23.04.2021 22:23:01
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
    ll a,b,c;
    cin >> a >> b >> c;
    ll g = gcd(a,gcd(b,c));
    ll ans = a/g - 1;
    ans += b/g - 1;
    ans += c/g - 1;
    cout << ans << endl;
}