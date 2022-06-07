/**
*    author:  shu8Cream
*    created: 04.06.2022 20:57:26
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
#define pcnt __builtin_popcountll
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

function<ll(ll,ll)> ope = [](ll a, ll b) { return gcd(a,b); };
function<ll(ll,ll)> update = [](ll a, ll b) { return b; };


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int n,q; cin >> n >> q;
    vi a(n); cin >> a;
    vi b(n); cin >> b;
    SegTree<ll> sta(n-1,0,ope,update);
    SegTree<ll> stb(n-1,0,ope,update);
    rep(i,n-1){
        sta.change(i,abs(a[i+1]-a[i]));
        stb.change(i,abs(b[i+1]-b[i]));
        debug(sta[i],stb[i]);
    }
    rep(qi,q){
        int h1,h2,w1,w2;
        cin >> h1 >> h2 >> w1 >> w2;
        --h1;--h2;--w1;--w2;
        ll ans = a[h1] + b[w1];
        ans = gcd(ans, sta.query(h1,h2));
        ans = gcd(ans, stb.query(w1,w2));
        cout << ans << endl;
    }
}