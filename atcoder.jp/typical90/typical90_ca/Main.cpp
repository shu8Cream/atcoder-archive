/**
*    author:  shu8Cream
*    created: 03.07.2021 23:14:30
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
    int h,w; cin >> h >> w;
    vvi a(h,vi(w)), b(h,vi(w));
    rep(i,h)rep(j,w) cin >> a[i][j];
    rep(i,h)rep(j,w) cin >> b[i][j];
    rep(i,h)rep(j,w) b[i][j]-=a[i][j];
    ll ans = 0;
    rep(i,h-1)rep(j,w-1){
        ans+=abs(b[i][j]);
        b[i][j+1]-=b[i][j];
        b[i+1][j]-=b[i][j];
        b[i+1][j+1]-=b[i][j];
        b[i][j]=0;
    }
    bool f = true;
    rep(i,h)rep(j,w) if(b[i][j]!=0){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    cout << ans << endl;
}