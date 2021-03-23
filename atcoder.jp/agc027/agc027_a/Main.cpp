/**
*    author:  shu8Cream
*    created: 23.03.2021 20:38:04
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
    ll n,x;
    cin >> n >> x;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(all(a));
    ll ans = 0;
    rep(i,n){
        x-=a[i];
        if(x>=0) ans++;
    }
    if(x>0) ans--;
    cout << ans << endl;
}