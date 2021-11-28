/**
*    author:  shu8Cream
*    created: 28.11.2021 20:52:28
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
const ll INF = 8e18;

template<class T> inline bool chmax(T& a, T b) {
    if (a < b) { a = b; return true; }
    return false;
}
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) { a = b; return true; }
    return false;
}

void debug_out() { cout << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
cout << H << " ";
debug_out(T...);
}

#ifdef _DEBUG
#define debug(...) debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll h,w,C,q; cin >> h >> w >> C >> q;
    vi cnt(C);
    set<int> yoko,tate;
    vi t(q),n(q),c(q);
    rep(i,q){
        cin >> t[i] >> n[i] >> c[i];
        n[i]--; c[i]--;
    }
    rrep(i,q){
        if(t[i]==1 && yoko.count(n[i])) continue;
        if(t[i]==2 && tate.count(n[i])) continue;
        cnt[c[i]] += (t[i]==1 ? w : h);
        if(t[i]==1) h--;
        if(t[i]==2) w--;
        if(t[i]==1) yoko.insert(n[i]);
        else tate.insert(n[i]);
    }
    rep(i,C) cout << cnt[i] << endl;
}