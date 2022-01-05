/**
*    author:  shu8Cream
*    created: 05.01.2022 00:02:35
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

// dp i,j i個目まででj個選択した時、
// modj=kの時
// Xとその和の差がmodjで０の最大値
ll dp[110][110];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,x; cin >> n >> x;
    vi a(n); rep(i,n) cin >> a[i];
    ll ans = INF;
    rep(mod,n+1){
        if(!mod) continue;
        rep(i,mod+1)rep(j,mod) dp[i][j] = -INF;
        dp[0][0] = 0;
        rep(i,n){
            rrep(j,mod){
                rep(k,mod)if(dp[j][k]>=0){
                    chmax(dp[j+1][(k+a[i])%mod], dp[j][k] + a[i]);
                }
            }
        }
        ll t = x%mod;
        if(dp[mod][t]>=0) chmin(ans,(x-dp[mod][t])/mod);
    }
    cout << ans << endl;
}