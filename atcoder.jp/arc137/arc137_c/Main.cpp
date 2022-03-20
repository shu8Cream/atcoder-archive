/**
*    author:  shu8Cream
*    created: 19.03.2022 20:47:56
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

int solve(vi a){
    int n = sz(a);
    sort(all(a));
    int m = a[n-1];
    if(m==n-1) return 0;
    rep(i,m){
        bool f = false;
        rep(j,n-1) if(a[j]==i){
            f = true;
            break;
        }
        if(f) continue;
        a[n-1] = i;
        if(solve(a)==0) return 1;
    }
    return 0;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // rep(i,10)rep(j,i+1,10)rep(k,j+1,10){
    //     vi a = {i,j,k};
    //     int n = sz(a);
    //     int chk = 1;
    //     int res = solve(a);
    //     if(a[n-1]-a[n-2]==1 && (a[n-1]+a[n-2]-2*n+1)%4!=0) chk = 0;
    //     // if(a[n-1]-a[n-2]==1) chk = 0;
    //     debug(a,":",res,chk);
    //     assert(res==chk);
    // }

    ll n; cin >> n;
    vi a(n); rep(i,n) cin >> a[i];
    bool f = true;
    if(a[n-1]-a[n-2]==1 && (a[n-1]+a[n-2]-2*n+1)%4!=0) f = false;
    cout << (f ? "Alice" : "Bob") << endl;
}