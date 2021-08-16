/**
*    author:  shu8Cream
*    created: 16.08.2021 14:49:22
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
    ll n,k; cin >> n >> k;
    vector<P> a(n);
    rep(i,n){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(all(a));
    vector<P> b(n);
    rep(i,n){
        b[i].second = k/n;
        b[i].first = a[i].second;
    }
    k%=n;
    rep(i,k) b[i].second++;
    sort(all(b));
    for(auto [f,s] : b){
        cout << s << endl;
    }
}