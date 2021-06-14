/**
*    author:  shu8Cream
*    created: 13.06.2021 20:50:37
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=(n-1); i>0; i--)
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
    rep(i,q){
        ll k; cin >> k;
        ll ok = 5e18, ng = 0;
        while(ok-ng>1){
            ll mid = (ok + ng) / 2;
            ll d = upper_bound(all(a),mid) - a.begin();
            ll nth = mid - d;
            // cerr << mid << " " << d << endl;
            if(nth>=k) ok = mid;
            else ng = mid;
        }
        cout << ok << endl;
    }
}