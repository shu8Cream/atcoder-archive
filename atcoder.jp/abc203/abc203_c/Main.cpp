/**
*    author:  shu8Cream
*    created: 10.07.2021 10:40:49
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
    map<ll,ll> m;
    rep(i,n){
        ll a,b; cin >> a >> b;
        m[a]+=b; 
    }
    ll ans = 0;
    for(auto [key,v] : m){
        if(key-ans>k){
            ans += k;
            k = 0;
            break; 
        }
        k -= key-ans;
        ans = key;
        k += v; 
    }
    ans += k;
    cout << ans << endl;
}