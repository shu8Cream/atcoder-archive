/**
*    author:  shu8Cream
*    created: 08.08.2021 01:02:48
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
    int n; cin >> n;
    vi a(n); rep(i,n) cin >> a[i];
    vi ra(n+1); rep(i,n) ra[i+1] = ra[i]+a[i];
    vi rra(n+1); rep(i,n) rra[i+1] = rra[i]+ra[i+1]; 
    vi aMax(n); aMax[0] = a[0];
    rep(i,n-1) aMax[i+1] = max(aMax[i],a[i+1]);
    rep(i,n){
        ll k = i+1;
        cout << aMax[i]*k + rra[i+1] << endl;
    }
}