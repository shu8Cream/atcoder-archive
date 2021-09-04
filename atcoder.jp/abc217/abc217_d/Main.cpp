/**
*    author:  shu8Cream
*    created: 04.09.2021 20:46:06
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
    ll l,q;
    cin >> l >> q;
    set<ll> s;
    s.insert(0);
    s.insert(l);
    rep(i,q){
        int c,x; cin >> c >> x;
        if(c==1){
            s.insert(x);
        }else{
            auto itr = s.lower_bound(x);
            // auto pit = itr-1;
            cout << *itr - *--itr << endl;
        }
    }
}