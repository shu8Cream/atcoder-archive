/**
*    author:  shu8Cream
*    created: 19.09.2021 21:55:34
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=(n-1); i>=0; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;
const ll INF = INT64_MAX;

template<class T> inline bool chmax(T& a, T b) {
    if (a < b) { a = b; return true; }
    return false;
}
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) { a = b; return true; }
    return false;
}

int LIS(vi &a){
    int n = sz(a);
    vi dp(n,INF);
    rep(i,n){
        auto itr = lower_bound(all(dp), a[i]);
        *itr = a[i];
    }
    return lower_bound(all(dp), INF) - dp.begin();
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,m; cin >> n >> m;
    vector<P> ab(m);
    vvi to(n);
    rep(i,m){
        int a,b; cin >> a >> b;
        a--; b--;
        ab[i] = {a,b};
        to[a].push_back(b);
    }
    rep(i,n) sort(rall(to[i]));
    vi c;
    rep(i,n){
        for(auto p : to[i]){
            c.push_back(p);
        }
    }
    cout << LIS(c) << endl;
}