/**
*    author:  shu8Cream
*    created: 26.05.2021 23:36:39
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (ll i=1; i<=(n); i++)
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
    ll N; cin >> N;
    rep(n,3500)rep(h,3500){
        ll a = N * n * h;
        ll b = 4*n*h-N*h-N*n;
        if(b && a%b==0 && a/b>0){
            cout << h << " " << n << " " << a/b << endl;
            return 0;
        } 
    }
}