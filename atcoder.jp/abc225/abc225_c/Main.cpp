/**
*    author:  shu8Cream
*    created: 30.10.2021 20:54:13
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

const vi key = {1,2,3,4,5,6,0};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    vvi b(n,vi(m));
    rep(i,n)rep(j,m) cin >> b[i][j];
    bool f = false;
    vi a(m);
    rep(i,m) a[i] = b[0][i]%7;
    int cnt = 0;
    rep(i,7-m+1){
        bool f2 = true;
        rep(j,m) if(a[j]!=key[i+j]) f2=false;
        if(f2) cnt++;
    }
    if(cnt) f = true;
    rep(i,m)rep(j,n){
        if(j && b[j][i]-7!=b[j-1][i]) f = false;
        if(a[i]!=b[j][i]%7) f = false;
    }
    cout << (f ? "Yes" : "No") << endl;
}