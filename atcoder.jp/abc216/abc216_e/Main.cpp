/**
*    author:  shu8Cream
*    created: 29.08.2021 21:44:21
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=(n-1); i>=0; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

template<class T> inline bool chmax(T& a, T b) {
    if (a < b) { a = b; return true; }
    return false;
}
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) { a = b; return true; }
    return false;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,k; cin >> n >> k;
    vi a(n); rep(i,n) cin >> a[i];
    sort(rall(a));
    ll ans = 0;
    ll cnt = 1;
    rep(i,n){
        if(k==0) break;
        if(k-(a[i]-a[i+1])*cnt>=0){
            ans += ((a[i]+1)*a[i]-a[i+1]*(a[i+1]+1))/2*cnt;
            k -= (a[i]-a[i+1])*cnt;
            cnt++;
        }else{
            ll t = k/cnt;
            ans += ((a[i]+1)*a[i]-(a[i]-t+1)*(a[i]-t))/2*cnt;
            // cout << ans << endl;
            ans += k%cnt*(a[i]-t);
            k = 0;
        }
        // cout << ans << " " << k << endl;
    }
    cout << ans << endl;
}