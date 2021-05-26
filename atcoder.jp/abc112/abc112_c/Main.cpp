/**
*    author:  shu8Cream
*    created: 26.05.2021 11:31:19
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
    vi x(n),y(n),h(n);
    rep(i,n) cin >> x[i] >> y[i] >> h[i];
    vi ans(3);
    rep(i,101)rep(j,101){
        ll H = 1;
        rep(k,n) if(h[k]) H = h[k] + abs(x[k]-i) + abs(y[k]-j);
        rep(k,n){
            if(h[k]!=max(H - abs(x[k]-i) - abs(y[k]-j),0LL)) break;
            if(k==n-1) cout << i << " " << j << " " << H << endl;
        }
    }
}