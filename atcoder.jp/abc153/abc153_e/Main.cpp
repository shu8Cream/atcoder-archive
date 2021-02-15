/**
*    author:  shu8Cream
*    created: 15.02.2021 20:10:05
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).rbegin(), (x).rend()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int h,n;
    cin >> h >> n;
    vi a(n),b(n);
    rep(i,n) cin >> a[i] >> b[i];
    vector<ll> dp(h+1,1e18);
    dp[0]=0;
    rep(i,n)rep(j,h+1){
        dp[min(j+a[i],h)]=min(dp[min(j+a[i],h)], dp[j]+b[i]);
    }
    cout << dp[h] << endl;
}