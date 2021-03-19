/**
*    author:  shu8Cream
*    created: 19.03.2021 19:55:28
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
    ll n,c;
    cin >> n >> c;
    vector<ll> x(n),v(n), rv(n+1),rrv(n+1),g(n+1);
    vector<ll> rv2(n+1),rrv2(n+1),g2(n+1);
    rep(i,n){
        cin >> x[i] >> v[i];
        rv[i+1]=rv[i]+v[i];
    }
    rep(i,n) rrv[i+1]=rrv[i]+v[n-1-i];
    rep(i,n) rv2[i+1]=rv[i+1];
    rep(i,n) rrv2[i+1]=rrv[i+1];

    rep(i,n) rv[i+1]-=x[i]*2;
    rep(i,n) rrv[i+1]-=(c-x[n-1-i]);
    rep(i,n) g[i+1]=max(g[i],rv[i+1]);

    rep(i,n) rv2[i+1]-=x[i];
    rep(i,n) rrv2[i+1]-=(c-x[n-1-i])*2;
    rep(i,n) g2[i+1]=max(g2[i],rv2[i+1]);

    ll ans = 0;
    rep(i,n+1){
        ans = max(ans, rrv[i]+g[n-i]);
        ans = max(ans, rrv2[i]+g2[n-i]);
    }
    cout << ans << endl;
}