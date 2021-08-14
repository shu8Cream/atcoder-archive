/**
*    author:  shu8Cream
*    created: 14.08.2021 20:49:18
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
    vi s(n),t(n);
    rep(i,n) cin >> s[i];
    ll m = 1e9+7, midx = 0;
    rep(i,n){
        cin >> t[i]; 
        chmin(m,t[i]);
        if(m==t[i]) midx = i;
    }
    ll tmp = 0;
    vi ans(n);
    rep(i,n){
        int pos = (midx+i)%n;
        if(!i){
            tmp = t[pos];
            ans[pos] = tmp;
            continue;
        }
        int prepos = (pos-1+n)%n;
        if(t[pos]<=tmp+s[prepos]){
            ans[pos] = t[pos];
            tmp = t[pos];
        }else{
            ans[pos] = tmp+s[prepos];
            tmp += s[prepos];
            t[pos] = tmp;
        }
    }
    rep(i,n) cout << ans[i] << endl;
}