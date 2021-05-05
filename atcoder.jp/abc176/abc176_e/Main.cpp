/**
*    author:  shu8Cream
*    created: 05.05.2021 00:14:06
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll h,w,m;
    cin >> h >> w >> m;
    vi col(h), row(w);
    vi hh(m), ww(m);
    rep(i,m){
        ll c,r; cin >> c >> r;
        c--; r--;
        hh[i]=c; ww[i]=r;
        col[c]++; row[r]++;
    }
    auto itr1 = *max_element(all(col));
    auto itr2 = *max_element(all(row));
    ll ans = itr1+itr2;
    ll Mh = 0, Mw = 0;
    rep(i,h) if(itr1==col[i]) Mh++;
    rep(i,w) if(itr2==row[i]) Mw++;
    ll range = Mh * Mw;
    rep(i,m){
        if(col[hh[i]]==itr1 && row[ww[i]]==itr2)
            range--;
    }
    if(range<=0) ans--;
    cout << ans << endl;
}