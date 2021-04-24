/**
*    author:  shu8Cream
*    created: 09.02.2021 15:33:47
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,C;
    cin >> n >> C;
    vvi d(C,vi (C));
    rep(i,C)rep(j,C) cin >> d[i][j];
    vvi c(n,vi (n));
    vvi t(3,vi(30));
    rep(i,n)rep(j,n){
        cin >> c[i][j];
        c[i][j]--;
        t[(i+j)%3][c[i][j]]++;
    }
    ll ans = 8e18;
    rep(i,C)rep(j,C)rep(k,C){
        if(i==j || j==k || k==i) continue;
        ll tmp = 0;
        rep(l,C) tmp+=d[l][i]*t[0][l];
        rep(l,C) tmp+=d[l][j]*t[1][l];
        rep(l,C) tmp+=d[l][k]*t[2][l];
        ans = min(ans,tmp);
    }
    cout << ans << endl;
}