/**
*    author:  shu8Cream
*    created: 27.05.2021 00:11:45
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=(n-1); i>=0; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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
    int n,x; cin >> n >> x;
    vi a(n); rep(i,n) cin >> a[i];
    ll ans = 0;
    rep(i,n-1){
        if(a[i]+a[i+1]<=x) continue;
        if(a[i]>x){
            ans+=a[i]-x + a[i+1];
            a[i]=x;
            a[i+1]=0;
        }else{
            ans += a[i+1] - (x-a[i]);
            a[i+1] = x-a[i];
        }
    }
    cout << ans << endl;
}