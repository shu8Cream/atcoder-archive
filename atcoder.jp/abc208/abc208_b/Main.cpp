/**
*    author:  shu8Cream
*    created: 16.08.2021 14:49:15
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

vi coin = {1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll p; cin >> p;
    reverse(all(coin));
    ll ans = 0;
    rep(i,10){
        ans += p/coin[i];
        p%=coin[i];
    }
    cout << ans << endl;
}