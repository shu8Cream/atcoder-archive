/**
*    author:  shu8Cream
*    created: 15.01.2022 14:23:02
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
    set<ll> yes;
    ll p = 2;
    while(p*(p-1)/2<=n){
        yes.insert(p*(p-1)/2);
        p++;
    }
    if(!yes.count(n)){
        cout << "No" << endl;
        return 0;
    }
    ll k = 2;
    while(k*(k-1)/2!=n) k++;
    vvi ans(k);
    ll t = k-1;
    ll el = 1;
    int cur = 0;
    while(t){
        rep(i,t) ans[cur].push_back(el+i); 
        rep(i,t) ans[cur+i+1].push_back(el+i);
        cur++;
        el+=t;
        t--;
    }
    cout << "Yes" << endl;
    cout << k << endl;
    rep(i,k){
        cout << k-1 << " ";
        rep(j,k-1) cout << ans[i][j] << " ";
        cout << endl;
    }
}