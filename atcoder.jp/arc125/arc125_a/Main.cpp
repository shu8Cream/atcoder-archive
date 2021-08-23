/**
*    author:  shu8Cream
*    created: 22.08.2021 20:55:50
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
    vi s(n),t(m);

    set<ll> ss,tt;
    rep(i,n) cin >> s[i];
    rep(i,m) cin >> t[i];
    rep(i,n) ss.insert(s[i]);
    rep(i,m) tt.insert(t[i]);
    for(auto p : tt){
        if(!ss.count(p)){
            cout << -1 << endl;
            return 0;
        }
    }
    int now = s[0];
    int next = 1e9;
    rep(i,n){
        if(s[0]!=s[i]) chmin(next, min(i,n-i));
    }
    ll ans = m;
    bool first = true;
    rep(i,m){
        if(first && now!=t[i]){
            ans+=next;
            first = false;
            now = t[i];
        }else if(now!=t[i]){
            ans++;
            now = t[i];
        }
    }
    cout << ans << endl;
}