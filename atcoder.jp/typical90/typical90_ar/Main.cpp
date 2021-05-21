/**
*    author:  shu8Cream
*    created: 22.05.2021 00:02:36
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
    int n,q;
    cin >> n >> q;
    vi a(n); rep(i,n) cin >> a[i];
    int shift = 0;
    rep(i,q){
        int t,x,y;
        cin >> t >> x >> y;
        x--; y--;
        x-=shift; y-=shift;
        x%=n; y%=n;
        if(x<0) x+=n;
        if(y<0) y+=n;
        if(t==1) swap(a[x],a[y]);
        if(t==2) shift++;
        if(t==3) cout << a[x] << endl;
    }
}