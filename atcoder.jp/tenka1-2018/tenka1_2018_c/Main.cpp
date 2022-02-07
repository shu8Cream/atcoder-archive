/**
*    author:  shu8Cream
*    created: 07.02.2022 21:33:21
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
    sort(all(a));
    deque<ll> p,q;
    rep(i,n) p.push_back(a[i]);
    q.push_back(p.front());
    p.pop_front();
    ll ans = 0;
    while(!p.empty()){
        ll f = p.front(), b = p.back();
        ll sf = q.front(), sb = q.back();
        if(max(max(max(abs(f-sf), abs(f-sb)), abs(b-sf)), abs(b-sb)) == abs(f-sf)){
            q.push_front(f);
            p.pop_front();
            ans += abs(f-sf);
        }else if(max(max(max(abs(f-sf), abs(f-sb)), abs(b-sf)), abs(b-sb)) == abs(f-sb)){
            q.push_back(f);
            p.pop_front();
            ans += abs(f-sb);
        }else if(max(max(max(abs(f-sf), abs(f-sb)), abs(b-sf)), abs(b-sb)) == abs(b-sf)){
            q.push_front(b);
            p.pop_back();
            ans += abs(b-sf);
        }else{
            q.push_back(b);
            p.pop_back();
            ans += abs(b-sb);
        }
    }
    cout << ans << endl;
}