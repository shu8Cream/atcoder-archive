/**
*    author:  shu8Cream
*    created: 30.12.2020 11:11:30
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n),s(n+1);
    rep(i,n) cin >> a[i];
    rep(i,n) s[i+1]=s[i]+a[i];
    rep(i,n){
        ll ans=0;
        rep(j,n-i){
            ans=max(ans, s[j+i+1]-s[j]);
        }
        cout << ans << endl;
    }
}