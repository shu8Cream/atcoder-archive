/**
*    author:  shu8Cream
*    created: 29.01.2022 20:45:40
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
    ll n,l,w; cin >> n >> l >> w;
    vi a(n); rep(i,n) cin >> a[i];
    vi b(2*n);
    for(int i=0; i<2*n; i+=2){
        b[i] = a[i/2];
        b[i+1] = a[i/2]+w;
    }
    vi t = b;
    debug(b);
    map<ll,ll> mp;
    vi cb = compress(b);
    debug(cb);
    rep(i,2*n) mp[cb[i]] = t[i];
    vi brid(200200);
    for(int i=0; i<2*n; i+=2){
        brid[cb[i]]++;
        brid[cb[i+1]]--;
    }
    rep(i,2*n)if(i) brid[i]+=brid[i-1];
    ll ans = 0;
    ll now = 0;
    rep(i,2*n){
        if(now!=-1 && brid[i]){
            ans+=(mp[i]-now+w-1)/w;
            debug(ans,now);
            now = -1;
        }else if(now==-1 && !brid[i]){
            now = mp[i];
            debug(now);
        }
    }
    if(now!=-1) ans+=(l-now+w-1)/w;
    cout << ans << endl;
}