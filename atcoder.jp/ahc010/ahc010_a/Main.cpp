/**
*    author:  shu8Cream
*    created: 24.04.2022 18:03:13
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

const int H = 30;
const int W = 30;
vc<string> tiles(30);

const vi di = {0,-1,0,1};
const vi dj = {-1,0,1,0};
const string direction = "DRUL";
const vvi to = {
    {1, 0, -1, -1},
    {3, -1, -1, 0},
    {-1, -1, 3, 2},
    {-1, 2, 1, -1},
    {1, 0, 3, 2},
    {3, 2, 1, 0},
    {2, -1, 0, -1},
    {-1, 3, -1, 1}
};

const vvi type_to = {
    {0,1},
    {0,3},
    {2,3},
    {1,2},
    {0,1,2,3},
    {0,1,2,3},
    {0,2},
    {1,3}
};

const vi rot90 = {1,2,3,0,5,4,7,6};

void input(){
    rep(i,H) cin >> tiles[i];
}

int calc_loop(int si, int sj, int type){
    int length = 0;
    for(auto sd : type_to[type]){
        int i = si;
        int j = sj;
        int d = sd;
        int res = 0;
        while(1){
            int d2 = to[tiles[i][j]-'0'][d];
            if (d2 == -1) {res=0;break;}
            i += di[d2];
            j += dj[d2];
            if (i < 0 || i >= 30 || j < 0 || j >= 30) {res=0;break;}
            d = (d2 + 2) % 4;
            res += 1;
            if (i == si && j == sj && d == sd) break;
        }
        chmax(length,res);
    }
    return length;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    input();
    vi ans(H*W);
    rep(i,H){
        rep(j,W){
            int type = tiles[i][j]-'0';
            int now = calc_loop(i,j,type);
            rep(k,3){
                type = rot90[type];
                int new_now = calc_loop(i,j,type);
                if(new_now>now){
                    now = new_now;
                    ans[i*W+j] = k+1;
                }
            }
        }
    }
    rep(i,900) cout << ans[i];
    cout << endl;
}