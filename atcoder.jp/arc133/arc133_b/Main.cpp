/**
*    author:  shu8Cream
*    created: 22.01.2022 20:50:33
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

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    vi p(n),q(n);
    rep(i,n) cin >> p[i];
    rep(i,n) cin >> q[i];
    vi q_pos(n+1,-1);
    rep(i,n) q_pos[q[i]] = i;
    vi dp(n+1,INF);
    for(auto a:p){
        vi targets;
        for(int i=a; i<=n; i+=a){
            targets.push_back(q_pos[i]);
        }
        sort(rall(targets));
        debug(targets);
        for(auto j:targets){
            ll k = lower_bound(all(dp),j) - dp.begin();
            dp[k] = j;
        }
        debug(dp);
    }
    ll ans = 0;
    while(dp[ans]!=INF) ans++;
    cout << ans << endl;
}