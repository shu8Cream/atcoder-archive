/**
*    author:  shu8Cream
*    created: 26.03.2022 20:26:36
**/

#include <bits/stdc++.h>
using namespace std;
#define overload3(a,b,c,d,...) d
#define rep1(i,n) for (int i=0; i<(n); i++)
#define rep2(i,a,n) for (int i=(a); i<(n); i++)
#define rep(...) overload3(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)
#define rrep1(i,n) for (int i=(n-1); i>=0; i--)
#define rrep2(i,a,n) for (int i=(n-1); i>=(a); i--)
#define rrep(...) overload3(__VA_ARGS__, rrep2, rrep1)(__VA_ARGS__)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
using ll = long long;
using P = pair<ll,ll>;
template<typename T> using vc = vector<T>;
template<typename T> using vv = vc<vc<T>>;
using vi = vc<ll>;
using vvi = vv<ll>;
const ll INF = 8e18;
template<typename T>istream& operator>>(istream&i,vc<T>&v){rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const T&v,const string& d=""){stringstream s;rep(i,sz(v))(i?s<<d:s)<<v[i];return s.str();}
template<typename T>ostream& operator<<(ostream&o,const vc<T>&v){if(sz(v))o<<join(v," ");return o;}
template<typename T1,typename T2>istream& operator>>(istream&i,pair<T1,T2>&v){return i>>v.first>>v.second;}
template<typename T1,typename T2>ostream& operator<<(ostream&o,const pair<T1,T2>&v){return o<<v.first<<","<<v.second;}
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

ll dp[200200][2];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,k; cin >> n >> k;
    vi a(n); cin >> a;
    vi b(n); cin >> b;
    dp[0][0] = 1; // A
    dp[0][1] = 1; // B
    rep(i,n)rep(j,2){
        if(dp[i][0] && abs(a[i]-a[i+1])<=k) dp[i+1][0] = 1;
        if(dp[i][0] && abs(a[i]-b[i+1])<=k) dp[i+1][1] = 1;
        if(dp[i][1] && abs(b[i]-a[i+1])<=k) dp[i+1][0] = 1;
        if(dp[i][1] && abs(b[i]-b[i+1])<=k) dp[i+1][1] = 1;
    }
    cout << ((dp[n-1][0] || dp[n-1][1]) ? "Yes" : "No") << endl;
}