/**
*    author:  shu8Cream
*    created: 02.01.2022 01:38:04
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
    int n; string s; cin >> n >> s;
    vi bl,wh;
    rep(i,n-1)if(s[i]=='x' && s[i+1]=='o') bl.push_back(i+1);
    rep(i,n-1)if(s[i]=='o' && s[i+1]=='x') wh.push_back(i+1);
    bl.push_back(n);
    wh.push_back(n);
    ll ans = 0;
    rep(i,n){
        int itB = lower_bound(all(bl),i) - bl.begin();
        int itW = lower_bound(all(wh),i) - wh.begin();
        if(s[i]=='x') ans+=n-bl[itB];
        else ans+=n-wh[itW];
        debug(itB,itW,bl[itB],wh[itW]);
        debug(n-bl[itB], n-wh[itW]);
    }
    cout << ans << endl;
}