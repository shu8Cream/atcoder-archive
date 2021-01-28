/**
*    author:  shu8Cream
*    created: 28.01.2021 21:16:41
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
    vector<ll> a(n), r(n+1);
    rep(i,n) cin >> a[i];
    rep(i,n) r[i+1]=r[i]+a[i];
    map<ll,ll> m;
    rep(i,n+1) m[r[i]]++;
    ll ans = 0;
    for(auto p : m){
        ans+=p.second*(p.second-1)/2;
    }
    cout << ans << endl;
}