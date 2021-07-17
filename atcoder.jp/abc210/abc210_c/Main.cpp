/**
*    author:  shu8Cream
*    created: 17.07.2021 20:50:22
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
    ll n,k; cin >> n >> k;
    vi c(n); rep(i,n) cin >> c[i];
    map<ll,ll> m;
    rep(i,k) m[c[i]]++;
    ll ans = m.size();
    rep(i,n-k){
        m[c[i]]--;
        if(m[c[i]]==0) m.erase(c[i]);
        m[c[i+k]]++;
        chmax(ans,(ll)m.size());
    }
    cout << ans << endl;
}