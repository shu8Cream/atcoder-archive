/**
*    author:  shu8Cream
*    created: 06.07.2021 21:26:21
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
    vvi p(h,vi(w));
    rep(i,h)rep(j,w) cin >> p[i][j];
    ll ans = 1;
    rep(b,1<<h){
        set<P> s; bool f = true;
        map<ll,ll> ms;
        ll cnt = 0;
        rep(i,h){
            set<P> t;
            map<ll,ll> mt;
            if(!(b>>i&1)) continue;
            if(f){
                rep(j,w) s.insert({j,p[i][j]});
                f=false;
            }
            rep(j,w){
                if(s.count({j,p[i][j]})){
                    t.insert({j,p[i][j]});
                    mt[p[i][j]]++;
                }
            }
            swap(s,t); swap(ms,mt);
            if(s.size()) cnt++;
        }
        for(auto [k,v] : ms){
            chmax(ans,v*cnt);
        }
    }
    cout << ans << endl;
}