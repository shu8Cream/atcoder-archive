/**
*    author:  shu8Cream
*    created: 24.01.2022 22:57:32
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
    map<ll,ll> odd,even;
    rep(i,n){
        if(i%2) odd[a[i]]++;
        else even[a[i]]++;
    }
    vector<P> ODD,EVEN;
    for(auto[k,v]:odd) ODD.push_back({v,k});
    for(auto[k,v]:even) EVEN.push_back({v,k});
    sort(rall(ODD));
    sort(rall(EVEN));
    if(ODD[0].second!=EVEN[0].second){
        cout << n-ODD[0].first-EVEN[0].first << endl;
    }else{
        ll ans = INF;
        if(sz(ODD)>1) chmin(ans,n-ODD[1].first-EVEN[0].first);
        if(sz(EVEN)>1) chmin(ans,n-ODD[0].first-EVEN[1].first);
        if(ans==INF) ans = n/2;
        cout << ans << endl;
    }
}