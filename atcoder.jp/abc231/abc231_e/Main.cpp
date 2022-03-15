/**
*    author:  shu8Cream
*    created: 14.03.2022 12:32:55
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

template <class T> string to_string(T s);
template <class S, class T> string to_string(pair<S, T> p);
string to_string(char c) { return string(1, c); }
string to_string(string s) { return s; }
string to_string(const char s[]) { return string(s); }

template <class T>
string to_string(T v) {
    if (v.empty()) return "{}";
    string ret = "{";
    for (auto x : v) ret += to_string(x) + ",";
    ret.back() = '}';
    return ret;
}
template <class S, class T>
string to_string(pair<S, T> p) {
    return "{" + to_string(p.first) + ":" + to_string(p.second) + "}";
}

void debug_out() { cout << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cout << to_string(H) << " ";
    debug_out(T...);
}

#ifdef _DEBUG
#define debug(...) debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

// 可変N進数の桁DP

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; ll x; cin >> n >> x;
    vi a(n); rep(i,n) cin >> a[i];
    vi dp(2,INF);
    dp[0] = 0;
    rep(i,n-1){
        ll d = a[i+1]/a[i];
        ll r = x%d;
        vi p(2,INF);
        swap(dp,p);
        rep(c,2)rep(nc,2){
            ll nr = r+c-nc*d;
            chmin(dp[nc],p[c]+abs(nr));
        }
        x/=d;
    }
    ll ans = INF;
    rep(c,2) chmin(ans,dp[c]+abs(x+c));
    cout << ans << endl;
}