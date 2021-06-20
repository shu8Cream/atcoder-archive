/**
*    author:  shu8Cream
*    created: 20.06.2021 13:23:44
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
    ll n; cin >> n;
    vi a(n); rep(i,n) cin >> a[i];
    map<ll,ll> m;
    rep(i,n) m[a[i]]++;
    ll ans = n*(n-1)/2;
    for(auto [k,v] : m){
        if(v>1) ans-=v*(v-1)/2;
    }
    cout << ans << endl;
}