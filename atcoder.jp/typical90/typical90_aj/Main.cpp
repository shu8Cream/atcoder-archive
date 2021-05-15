/**
*    author:  shu8Cream
*    created: 15.05.2021 16:03:28
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,Q;
    cin >> n >> Q;
    vi x(n),y(n);
    ll mX = 8e18, mY = 8e18, MX = -8e18, MY = -8e18;
    rep(i,n){
        ll a,b; cin >> a >> b;
        x[i] = a-b;
        y[i] = a+b;
        mX = min(mX, x[i]);
        mY = min(mY, y[i]);
        MX = max(MX, x[i]);
        MY = max(MY, y[i]);
    }
    rep(i,Q){
        ll q; cin >> q; q--;
        ll r1 = abs(x[q]-mX);
        ll r2 = abs(y[q]-mY);
        ll r3 = abs(x[q]-MX);
        ll r4 = abs(y[q]-MY);
        cout << max({r1,r2,r3,r4}) << endl;
    }
}