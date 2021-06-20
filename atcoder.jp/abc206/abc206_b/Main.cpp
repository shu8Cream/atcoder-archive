/**
*    author:  shu8Cream
*    created: 20.06.2021 13:23:35
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (ll i=0; i<(n); i++)
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
    ll n;
    cin >> n;
    rep(i,50000000){
        if((i+1)*(i+2)/2>=n){
            cout << i+1 << endl;
            return 0; 
        }
    }
}