/**
*    author:  shu8Cream
*    created: 24.05.2021 21:38:04
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
    int n,k;
    cin >> n >> k;
    vi a;
    rep(i,n){
        ll p,q; cin >> p >> q;
        a.push_back(p-q);
        a.push_back(q);
    }
    sort(rall(a));
    ll ans = 0;
    rep(i,k) ans+=a[i];
    cout << ans << endl;
}