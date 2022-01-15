/**
*    author:  shu8Cream
*    created: 15.01.2022 20:45:45
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

template <typename T>
vector<T> compress(vector<T> &a){
    auto b = a;
    sort(all(b));
    b.erase(unique(all(b)), b.end());
    for(auto &p:a) p = lower_bound(all(b),p) - b.begin();
    return a;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,q; cin >> n >> q;
    vi A(n); rep(i,n) cin >> A[i];
    vi B = A;
    vi a = compress(B);
    map<ll,ll> dict;
    rep(i,n) dict[A[i]] = a[i];
    debug(a);
    vvi to(n);
    rep(i,n) to[a[i]].push_back(i+1);
    rep(i,q){
        ll x,k; cin >> x >> k;
        if(!dict.count(x)){
            cout << -1 << endl;
            continue;
        }
        if(sz(to[dict[x]])<k){
            cout << -1 << endl;
            continue;
        }
        cout << to[dict[x]][k-1] << endl;
    }
}