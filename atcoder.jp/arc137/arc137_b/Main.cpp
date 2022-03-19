/**
*    author:  shu8Cream
*    created: 19.03.2022 20:47:46
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

template<class T>
class SegTree {
    int n;                      // 葉の数
    vector<T> data;             // データ格納
    T e;                        // 単位元かつ初期値
    function<T(T,T)> ope;       // 区間クエリの演算
    function<T(T,T)> update;    // 一点更新で使う演算

    T _query(int a, int b, int k, int l, int r) {
        if(r<=a || b<=l) return e;
        if(a<=l && r<=b) return data[k];
        else{
            T c1 = _query(a, b, 2*k+1, l, (l+r)/2);
            T c2 = _query(a, b, 2*k+2, (l+r)/2,r);
            return ope(c1,c2);
        }
    }

public:
    SegTree(size_t _n, T _e, function<T(T,T)> _ope,
            function<T(T,T)> _update)
        : e(_e), ope(_ope), update(_update) {
        n = 1;
        while(n<_n) n *= 2;
        data = vector<T>(2*n-1,e);
    }

    void change(int i, T x) {
        i += n-1;
        data[i] = update(data[i],x);
        while(i>0){
            i = (i-1)/2;
            data[i] = ope(data[i*2+1], data[i*2+2]);
        }
    }

    T query(int a, int b){
        return _query(a,b,0,0,n);
    }

    T operator[](int i) {
        return data[i+n-1];
    }
};

function<ll(ll,ll)> ope1 = [](ll a, ll b) { return max(a,b); };
function<ll(ll,ll)> ope2 = [](ll a, ll b) { return min(a,b); };
function<ll(ll,ll)> update = [](ll a, ll b) { return b; };

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    vi a(n); rep(i,n) cin >> a[i];
    vi r(n+1);
    rep(i,n) r[i+1] = r[i] + (a[i] ? 1 : -1);
    
    SegTree<ll> st1(n+1,-INF,ope1,update);
    SegTree<ll> st2(n+1,INF,ope2,update);

    rep(i,n+1){
        st1.change(i,r[i]); 
        st2.change(i,r[i]); 
    }

    ll mx = 0, mn = 0;
    rep(i,n){
        chmax(mx, st1.query(i+1,n+2) - r[i]);
        chmax(mn, r[i] - st2.query(i+1,n+2));
    }
    cout << mn + mx + 1 << endl;
}