/**
*    author:  shu8Cream
*    created: 27.02.2022 21:07:49
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

template<typename T>
struct BIT{
public:
    int n; vector<T> a;
    BIT(int n_):n(n_),a(n+1,0){}

    void add(int idx, T x){
        idx++;
        if(idx<=0 || n<idx){ cerr << "Index error" << endl; return; }
        for(int i=idx; i<=n; i+=i&(-i)){
            a[i]+=x;
        }
    }

    T sum(int idx){
        T res = 0;
        idx++;
        if(idx<0 || n<idx){ cerr << "Index error" << endl; return 0; }
        if(idx==0) return 0;
        for(int i=idx; i>0; i-=(i&-i)){
            res+=a[i];
        }
        return res;
    }

    T sum(int l, int r){
        if(l==0) return sum(r-1);
        return sum(r-1)-sum(l-1);
    }
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    vi a(n),b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    bool f = false;
    BIT<int> bita(5050),bitb(5050);
    ll cnta = 0, cntb = 0;
    rep(i,n){
        cnta+=bita.sum(5050-1)-bita.sum(a[i]);
        bita.add(a[i],1);
        cntb+=bitb.sum(5050-1)-bitb.sum(b[i]);
        bitb.add(b[i],1);
    }
    debug(cnta,cntb);
    if(cnta%2==cntb%2) f = true;
    sort(all(a));
    sort(all(b));
    rep(i,n-1)if(a[i]==a[i+1]) f = true;
    if(a!=b) f = false;
    cout << (f ? "Yes" : "No") << endl;
}