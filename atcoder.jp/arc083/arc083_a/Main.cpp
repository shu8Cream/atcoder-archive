/**
*    author:  shu8Cream
*    created: 19.01.2022 23:08:28
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
    double a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;
    double mx = 0;
    ll water = 0, sugar = 0;
    rep(i,f/100/a+1){
        rep(j,f/100/b+1){
            rep(k,f/c+1){
                rep(l,f/d+1){
                    if(100.0*e/(100.0+e)<100.0*(k*c+l*d)/(i*a*100+j*b*100+k*c+l*d)) continue;
                    if(i*a*100+j*b*100+k*c+l*d>f) continue;
                    chmax(mx,100.0*(k*c+l*d)/(i*a*100+j*b*100+k*c+l*d));
                    debug(mx);
                    if(mx==100.0*(k*c+l*d)/(i*a*100+j*b*100+k*c+l*d)){
                        water = i*a*100+j*b*100;
                        sugar = k*c+l*d;
                    }
                }
            }
        }
    }
    cout << water+sugar << " " << sugar << endl;
}