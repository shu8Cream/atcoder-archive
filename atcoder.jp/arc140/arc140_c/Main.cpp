/**
*    author:  shu8Cream
*    created: 15.05.2022 20:51:28
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

int LIS(vi &a){
    int n = sz(a);
    vi dp(n,INF);
    rep(i,n){
        auto itr = lower_bound(all(dp), a[i]);
        *itr = a[i];
    }
    return lower_bound(all(dp), INF) - dp.begin();
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int n,x; cin >> n >> x;
    vi p1,p2;
    vi a;
    rep(i,1,n+1)if(x!=i) a.push_back(i);
    
    int l=0, r=n-2;
    while(l<=r){
        p1.push_back(a[l++]);
        if(l>r)break;
        p1.push_back(a[r--]);
    }
    p1.push_back(x);
    reverse(all(p1));
    l=0, r=n-2;
    while(l<=r){
        p2.push_back(a[r--]);
        if(l>r)break;
        p2.push_back(a[l++]);
    }
    p2.push_back(x);
    reverse(all(p2));

    vi t1,t2;
    rep(i,sz(p1)-1) t1.push_back(abs(p1[i]-p1[i+1]));
    rep(i,sz(p2)-1) t2.push_back(abs(p2[i]-p2[i+1]));

    int s1 = LIS(t1);
    int s2 = LIS(t2);
    debug(p1);
    debug(p2);
    assert(sz(p1)==n);
    assert(sz(p2)==n);
    assert(s1>=n-2 || s2>=n-2);

    if(s1>s2){
        rep(i,sz(p1)) cout << p1[i] << " ";
        cout << endl;
    }else{
        rep(i,sz(p2)) cout << p2[i] << " ";
        cout << endl;
    }
}