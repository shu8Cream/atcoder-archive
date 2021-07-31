/**
*    author:  shu8Cream
*    created: 31.07.2021 20:47:33
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
    int n,m; cin >> n >> m;
    vi a(n); rep(i,n) cin >> a[i];
    vi b(m); rep(i,m) cin >> b[i];
    sort(all(a));
    sort(all(b));
    ll ans = 1e9+7;
    rep(i,n){
        int itr = lower_bound(all(b), a[i]) - b.begin();
        chmin(ans,abs(a[i]-b[itr]));
        if(itr) chmin(ans,abs(a[i]-b[itr-1]));
    }
    cout << ans << endl;
}