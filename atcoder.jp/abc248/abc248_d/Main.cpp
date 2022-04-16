/**
*    author:  shu8Cream
*    created: 16.04.2022 20:47:20
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

const int MAX_VAL = 500500;
int a[MAX_VAL];     //要素
int cnt[MAX_VAL];   //区間内のiの個数
int res;            //区間内の種類の数
 
class Mo{
private:
    vector<int> left, right, value;
    const int width;
    void add(const int id, const int x);
    void del(const int id, const int x);
 
public:
    vector<int> ans;
 
    Mo(const int n) : width((int)sqrt(n)){}
    // クエリ[l,r)
    void insert(const int l, const int r, const int x){
        left.push_back(l), right.push_back(r);
        value.push_back(x);
    }
    void solve(){
        const int sz = (int)left.size();
        int nl = 0, nr = 0;
        vector<int> ord(sz);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](const int a, const int b){
            const int c = left[a] / width, d = left[b] / width;
            return (c == d) ? ((c & 1) ? (right[b] < right[a]) : (right[a] < right[b])) : (c < d);
        });
        ans.resize(sz);
        for(const int id : ord){
            while(nl > left[id]) add(--nl, value[id]);
            while(nr < right[id]) add(nr++, value[id]);  //add
            while(nl < left[id]) del(nl++, value[id]);
            while(nr > right[id]) del(--nr, value[id]);  //del
            ans[id] = cnt[value[id]];
        }
    }
};
 
//idは元の配列のインデックス
void Mo::add(const int id, const int x){
    ++cnt[a[id]];
}
 
void Mo::del(const int id, const int x){
    --cnt[a[id]];
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    ll n; cin >> n;
    rep(i,n) cin >> a[i];
    Mo mo(n+1);
    int q; cin >> q;
    int l,r,X;
    rep(i,q){
        cin >> l >> r >> X;
        --l; mo.insert(l,r,X);
    }
    mo.solve();
    const auto& ans = mo.ans;
    rep(i,q) cout << ans[i] << "\n";
    return 0;
}