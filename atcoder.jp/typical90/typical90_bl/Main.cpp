/**
*    author:  shu8Cream
*    created: 01.07.2021 21:34:45
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
    int n,q; cin >> n >> q;
    vi a(n); rep(i,n) cin >> a[i];
    vi b(n); rep(i,n-1) b[i+1]=a[i+1]-a[i];
    ll ans = 0;
    rep(i,n) ans += abs(b[i]);
    rep(i,q){
        ll l,r,v; cin >> l >> r >> v;
        ll f = abs(b[l-1]) + abs(b[r]);
        if(l>=2) b[l-1]+=v;
        if(r<=n-1) b[r]-=v;
        ll t = abs(b[l-1]) + abs(b[r]);
        ans += t-f;
        cout << ans << endl; 
    }
}