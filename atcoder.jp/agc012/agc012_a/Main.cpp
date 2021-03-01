/**
*    author:  shu8Cream
*    created: 02.03.2021 00:03:30
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
    int n;
    cin >> n;
    vector<ll> a(3*n);
    rep(i,3*n) cin >> a[i];
    sort(all(a));
    ll ans = 0;
    rep(i,n) ans+=a[n+i*2];
    cout << ans << endl;
}