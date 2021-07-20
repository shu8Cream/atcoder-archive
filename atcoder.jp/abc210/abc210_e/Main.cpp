/**
*    author:  shu8Cream
*    created: 20.07.2021 23:05:07
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
    ll n,m; cin >> n >> m;
    vector<P> ca;
    rep(i,m){
        ll a,c; cin >> a >> c;
        ca.push_back({c,a});
    }
    sort(all(ca));
    ll cur = n;
    ll ans = 0;
    for(auto p : ca){
        ll c = p.first, a = p.second;
        ans += (cur-gcd(cur,a)) * c;
        cur = gcd(cur,a);
    }
    if(cur==1) cout << ans << endl;
    else cout << -1 << endl;
}