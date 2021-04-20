/**
*    author:  shu8Cream
*    created: 14.04.2021 10:16:42
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
    int n;
    cin >> n;
    vi a(n),b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    sort(all(a)); sort(all(b));
    ll ans = 0;
    rep(i,n){
        ans+=abs(a[i]-b[i]);
    }

    cout << ans << endl;
}