/**
*    author:  shu8Cream
*    created: 18.11.2021 21:19:18
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
    int n,t; cin >> n >> t;
    vi a(n); rep(i,n) cin >> a[i];
    ll mx = a[n-1], mn = 1e9;
    vi b;
    rrep(i,n-1){
        if(mx<=a[i]){
            if(mn<mx) b.push_back(mx-mn);
            mx = a[i]; mn = 1e9;
        }else chmin(mn,a[i]);
    }
    if(mn<mx) b.push_back(mx-mn);
    int ans = 0;
    rep(i,sz(b)) debug(b[i]);
    sort(rall(b));
    rep(i,sz(b)) if(b[0]==b[i]) ans++;
    cout << ans << endl;
}