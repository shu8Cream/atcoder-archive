/**
*    author:  shu8Cream
*    created: 28.08.2021 11:04:04
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

ll dp[3030][3030][4];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int r,c,k; cin >> r >> c >> k;
    vvi gr(r, vi(c));
    rep(i,k){
        int a,b,v; cin >> a >> b >> v;
        a--; b--;
        gr[a][b]=v;
    }
    rep(i,r)rep(j,c){
        rrep(k,3) chmax(dp[i][j][k+1],dp[i][j][k]+gr[i][j]);
        rep(k,4){
          if(i+1<r) chmax(dp[i+1][j][0], dp[i][j][k]);
          if(j+1<c) chmax(dp[i][j+1][k], dp[i][j][k]);
        }
    }

    ll ans = 0;
    rep(i,4) chmax(ans,dp[r-1][c-1][i]);
    cout << ans << endl;
}