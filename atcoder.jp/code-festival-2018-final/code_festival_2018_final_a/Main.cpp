/**
*    author:  shu8Cream
*    created: 11.05.2021 19:38:49
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vvi rail(n);
    rep(i,m){
        ll a,b,l; cin >> a >> b >> l;
        a--; b--;
        rail[a].push_back(l);
        rail[b].push_back(l);
    }
    ll ans = 0;
    rep(i,n){
        sort(all(rail[i]));
        for(auto p : rail[i]){
            ans += upper_bound(all(rail[i]), 2540-p) - lower_bound(all(rail[i]), 2540-p);
            if(p==2540/2) ans--;
        }
    }
    cout << ans/2 << endl;
}