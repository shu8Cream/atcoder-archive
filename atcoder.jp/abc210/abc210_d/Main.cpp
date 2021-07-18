/**
*    author:  shu8Cream
*    created: 17.07.2021 20:50:48
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (ll i=0; i<(n); i++)
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
    ll h,w,c; cin >> h >> w >> c;
    vvi a(h,vi(w));
    rep(i,h)rep(j,w) cin >> a[i][j];
    ll ans = 8e18;
    vector<P> vec(h*w);
    rep(i,h)rep(j,w) vec[i*w+j]={a[i][j], i*w+j};
    sort(all(vec));
    rep(k,min(100LL,h*w)){
        auto [v,xy] = vec[k];
        ll x = xy/w, y = xy%w;
        rep(i,h)rep(j,w){
            if(i==x && j==y) continue;
            chmin(ans, v+a[i][j]+c*abs(i-x)+c*abs(j-y));
        } 
    }
    rep(i,h)rep(j,w){
        for(int x=max(0LL,i-10); x<min(i+11,h); x++){
            for(int y=max(0LL,j-10); y<min(j+11,w); y++){
                if(i==x && j==y) continue;
                chmin(ans,a[x][y]+a[i][j]+c*abs(i-x)+c*abs(j-y));
            }
        }
    }
    cout << ans << endl;
}