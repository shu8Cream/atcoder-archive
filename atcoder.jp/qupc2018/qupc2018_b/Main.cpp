/**
*    author:  shu8Cream
*    created: 25.02.2022 15:17:25
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
    int q; cin >> q;
    rep(i,q){
        ll a,b,c; cin >> a >> b >> c;
        if(c%2){
            cout << "No" << endl;
            continue;
        }
        ll sum = a*100 + b*10 + c;
        ll half = 0;
        auto bin_search = [&](ll x, ll mny)->void{
            ll ng = x+1, ok = 0;
            while(ng-ok>1){
                ll md = ok + (ng-ok)/2;
                if(half+md*mny<=sum/2) ok = md;
                else ng = md;
            }
            half+=ok*mny;
        };
        bin_search(a,100);
        bin_search(b,10);
        bin_search(c,1);
        if(half==sum/2){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}