/**
*    author:  shu8Cream
*    created: 06.07.2021 23:58:48
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=(n-1); i>=0; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

template<class T> inline bool chmax(T& a, T b) {
    if (a < b) { a = b; return true; }
    return false;
}
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) { a = b; return true; }
    return false;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vi x(n),y(n);
    rep(i,n) cin >> x[i] >> y[i];
    sort(all(x)); sort(all(y));
    ll ans = 0;
    ll X = x[n/2], Y = y[n/2];
    rep(i,n) ans+=abs(x[i]-X) + abs(y[i]-Y);
    cout << ans << endl;
}