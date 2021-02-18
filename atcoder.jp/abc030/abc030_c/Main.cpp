/**
*    author:  shu8Cream
*    created: 18.02.2021 15:52:03
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
    ll n,m,x,y;
    cin >> n >> m >> x >> y;
    vector<ll> a(n),b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    ll ans = 0;
    ll d = 0, tmp = 0;
    while(d<n){
        auto c = lower_bound(all(b), a[d]+x) - b.begin();
        if(c==m) break;
        d = lower_bound(all(a), b[c]+y) - a.begin();
        if(d<=tmp) break;
        tmp=d;
        ans++;
    }
    cout << ans << endl;
}