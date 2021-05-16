/**
*    author:  shu8Cream
*    created: 16.05.2021 20:59:44
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
    vi pow2(60);
    pow2[0] = 1;
    rep(i,59) pow2[i+1]=pow2[i]*2;
    ll ans = 8e18;
    rep(i,60){
        ll a = n / pow2[i];
        ll c = n - pow2[i] * a;
        if(c<0) continue;
        chmin(ans, a+i+c);
    }
    cout << ans << endl;
}