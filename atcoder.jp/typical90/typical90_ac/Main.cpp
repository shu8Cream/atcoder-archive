/**
*    author:  shu8Cream
*    created: 21.08.2021 13:28:20
**/

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
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

int op(int a, int b) { return max(a,b); }
int e() { return 0; }
int mapping(int f, int x) { return max(f,x); }
int composition(int f, int g) { return max(f,g); }
int id() { return 0; }

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int w,n; cin >> w >> n;
    lazy_segtree<int, op, e, int, mapping, composition, id> seg(w);
    rep(i,n){
        int l,r; cin >> l >> r;
        int mxH = seg.prod(l-1,r)+1;
        seg.apply(l-1,r,mxH);
        cout << mxH << endl;
    }
}