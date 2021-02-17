/**
*    author:  shu8Cream
*    created: 17.02.2021 11:56:44
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll h,w;
    cin >> h >> w;
    ll ans = 1e18;
    ll a = (w+1)/3 * h;
    ll b = h/2 * (w-(w+1)/3);
    ll c = (h-h/2) * (w-(w+1)/3);
    ans = min(ans, max({a,b,c}) - min({a,b,c}));
    ans = min(ans, h);
    swap(h,w);
    a = (w+1)/3 * h;
    b = h/2 * (w-(w+1)/3);
    c = (h-h/2) * (w-(w+1)/3);
    ans = min(ans, max({a,b,c}) - min({a,b,c}));
    ans = min(ans, h);
    if(h%3==0 || w%3==0) ans=0;
    cout << ans << endl;
}