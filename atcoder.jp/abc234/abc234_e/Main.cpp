/**
*    author:  shu8Cream
*    created: 09.01.2022 14:39:59
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
const ll INF = 9e18;

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
    ll x; cin >> x;
    set<ll> tousa;
    rep(d,10){
        rep(i,10){
            int c = i;
            ll res = 0;
            ll pres = -1;
            while(1){
                pres = res;
                if(INF/10<res) break;
                res*=10;
                res+=c;
                tousa.insert(res);
                if(pres==res) break;
                c+=d;
                if(c>9) break;
            }
            c = i;
            res = 0;
            pres = -1;
            while(1){
                pres = res;
                if(INF/10<res) break;
                res*=10;
                res+=c;
                tousa.insert(res);
                if(pres==res) break;
                c-=d;
                if(c<0) break;
            }
        }
    }
    
    cout << *tousa.lower_bound(x) << endl;
}