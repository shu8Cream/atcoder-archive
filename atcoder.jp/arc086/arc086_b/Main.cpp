/**
*    author:  shu8Cream
*    created: 20.08.2021 22:31:08
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
    int mx=0;
    rep(i,n) if(abs(a[i])>abs(a[mx])) mx = i;

    if(a[mx]==0){
        cout << 0 << endl;
    }else if(a[mx]>0){
        cout << 2*n << endl;
        rep(i,n){
            cout << mx+1 << " " << i+1 << endl;
            cout << mx+1 << " " << i+1 << endl;
            mx = i;
        }
    }else{
        cout << 2*n << endl;
        rrep(i,n){
            cout << mx+1 << " " << i+1 << endl;
            cout << mx+1 << " " << i+1 << endl;
            mx = i;
        }
    }
}