/**
*    author:  shu8Cream
*    created: 16.01.2021 20:55:00
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
    vector<ll> a(n),b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    vector<ll> dp(n);
    ll amax = a[0];
    dp[0]=a[0]*b[0];
    rep(i,n){
        amax=max(amax, a[i]);
        if(i!=0) dp[i]=max(dp[i-1], amax*b[i]);
        cout << dp[i] << endl;
    }
}