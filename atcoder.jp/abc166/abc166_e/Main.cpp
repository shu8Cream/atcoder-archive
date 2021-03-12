/**
*    author:  shu8Cream
*    created: 12.03.2021 13:02:14
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
    vi a(n);
    rep(i,n) cin >> a[i];
    map<ll,ll> mp;
    ll ans = 0;
    rep(i,n) mp[i+a[i]]++;
    rep(i,n) if(mp.count(i-a[i])) ans+=mp[i-a[i]];
    cout << ans << endl;
}