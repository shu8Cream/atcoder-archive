/**
*    author:  shu8Cream
*    created: 08.03.2021 21:29:32
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<P> a(n);
    rep(i,n){
        ll x,l;
        cin >> x >> l;
        a[i]={x+l,x-l};
    }
    sort(all(a));
    int ans = 0;
    ll cur = -1e18;
    rep(i,n){
        if(a[i].second<cur) continue;
        ans++;
        cur = a[i].first;
    }
    cout << ans << endl;
}