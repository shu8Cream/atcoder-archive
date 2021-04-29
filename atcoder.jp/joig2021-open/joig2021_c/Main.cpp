/**
*    author:  shu8Cream
*    created: 29.04.2021 14:21:20
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
    vector<int> a(n),cnt(n+1);
    rep(i,n) cin >> a[i];
    rep(i,n) cnt[i+1]=cnt[i]+a[i];
    int ans = cnt[n];
    rep(i,n){
        ans = min(ans, i+1-cnt[i+1]+cnt[n]-cnt[i+1]);
    }
    cout << ans << endl;
}