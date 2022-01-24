/**
*    author:  shu8Cream
*    created: 23.01.2022 21:55:53
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
    int n; cin >> n;
    vi a(n); rep(i,n) cin >> a[i];

    auto check = [&](double x)->bool{
        using vd = vector<double>;
        using vvd = vector<vd>;
        vvd dp(n+1,vd(2));
        dp[1][0] = 0;
        dp[1][1] = a[0] - x;
        rep(i,n-1){
            dp[i+2][0] += dp[i+1][1];
            dp[i+2][1] += max(dp[i+1][0],dp[i+1][1]) + a[i+1]-x;
        }
        if(dp[n][0]>=0 || dp[n][1]>=0) return true;
        else return false;
    };

    double ng = 2e9, ok = 0;
    ll loop = 100;
    while(loop--){
        double mid = (ng+ok)/2;
        if(check(mid)) ok = mid;
        else ng = mid;
    } 

    auto check2 = [&](ll x)->bool{
        vvi dp(n+1,vi(2));
        if(a[0]>=x) dp[1][1] = 1;
        else dp[1][1] = -1;
        rep(i,n-1){
            dp[i+2][0] += dp[i+1][1];
            if(a[i+1]>=x) dp[i+2][1] += max(dp[i+1][0],dp[i+1][1]) + 1;
            else dp[i+2][1] += max(dp[i+1][0],dp[i+1][1]) - 1;
        }
        if(dp[n][0]>0 || dp[n][1]>0) return true;
        else return false;
    };

    ll ng2 = 2e9, ok2 = 0;
    while(ng2-ok2>1){
        ll mid = (ng2+ok2)/2;
        if(check2(mid)) ok2 = mid;
        else ng2 = mid;
    } 
    printf("%.10lf\n%d\n",ok,ok2);
}