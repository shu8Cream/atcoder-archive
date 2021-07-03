/**
*    author:  shu8Cream
*    created: 03.07.2021 16:02:51
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
    ll n; cin >> n;
    vi a(n),aa(2*n);
    rep(i,n) cin >> a[i];
    rep(i,n){
        aa[i] = a[i];
        aa[n+i] = a[i];
    }
    vi r(2*n+1);
    rep(i,2*n) r[i+1] = r[i]+aa[i];
    if(r[n]%10!=0){
        cout << "No" << endl;
        return 0;
    }
    bool f = false;
    rep(i,2*n+1){
        ll tmp = r[n]/10 + r[i];
        auto itr = lower_bound(all(r), tmp) - r.begin();
        if(r[itr]-r[i]==r[n]/10) f=true;
    }
    if(r[n]%10!=0) f = false;
    cout << (f ? "Yes" : "No") << endl;
}