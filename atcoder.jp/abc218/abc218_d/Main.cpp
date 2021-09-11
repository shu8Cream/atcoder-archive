/**
*    author:  shu8Cream
*    created: 11.09.2021 20:40:38
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
    vector<P> xy(n);
    set<P> rem;
    rep(i,n){
        cin >> xy[i].first >> xy[i].second;
        rem.insert(xy[i]);
    }
    ll ans = 0;
    rep(i,n)rep(j,i){
        if(xy[i].first==xy[j].first || xy[i].second==xy[j].second) continue;
        if(rem.count({xy[i].first,xy[j].second}) && rem.count({xy[j].first,xy[i].second}))
            ans++;
    }
    cout << ans/2 << endl;
}