/**
*    author:  shu8Cream
*    created: 23.01.2022 22:10:29
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
    int n; cin >> n;
    ll full = (1<<n)-1;
    vector<P> c(full);
    rep(i,full){
        cin >> c[i].first;
        c[i].second = i+1;
    }
    sort(all(c));
    vi check(full+1);
    int cur = 0;
    vi set;
    ll ans = 0;
    while(accumulate(all(check),0)!=full){
        if(check[c[cur].second]==0){
            set.push_back(c[cur].second);
            debug(c[cur].second);
            check[c[cur].second] = 1;
            ans+=c[cur].first;
            cur++;
        }else{
            cur++;
            continue;
        }
        int N = sz(set);
        for(int bit=1; bit<(1<<N); bit++){
            ll tar = 0;
            rep(i,N)if(bit>>i&1) tar^=set[i];
            check[tar] = 1;
        }
        debug(check);
    }
    
    cout << ans << endl;
}