/**
*    author:  shu8Cream
*    created: 22.05.2021 00:29:05
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
    vi a(n),b(n),c(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    rep(i,n) cin >> c[i];
    rep(i,n) a[i]%=46;
    rep(i,n) b[i]%=46;
    rep(i,n) c[i]%=46;
    map<ll,ll> aa,bb,cc;
    rep(i,n) aa[a[i]]++;
    rep(i,n) bb[b[i]]++;
    rep(i,n) cc[c[i]]++; 
    ll ans = 0;
    for(auto [fa,sa] : aa){
        for(auto [fb,sb] : bb){
            for(auto [fc,sc] : cc){
                if((fa+fb+fc)%46==0) ans+=sa*sb*sc;
            }
        }
    }
    cout << ans << endl;
}