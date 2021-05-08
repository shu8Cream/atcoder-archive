/**
*    author:  shu8Cream
*    created: 08.05.2021 20:47:42
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
    int n; cin >> n;
    vi a(n); rep(i,n) cin >> a[i];
    vi b(n);
    rep(i,n) b[i]=a[i]%200;
    map<ll,ll> m;
    rep(i,n) m[b[i]]++;
    ll ans = 0;
    for(auto [k,v] : m){
        ans += v*(v-1)/2;
    }
    cout << ans << endl;
}