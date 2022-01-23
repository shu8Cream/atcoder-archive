/**
*    author:  shu8Cream
*    created: 23.01.2022 20:51:22
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
    ll n; cin >> n;
    vvi a(2*n,vi(2*n,-1));
    rep(i,2*n-1){
        for(int j=2*n-1-i; j>0; j--){
            cin >> a[i][2*n-j];
        }
    }
    // rep(i,2*n){
    //     rep(j,2*n) cout << a[i][j] << " ";
    //     cout << endl;
    // }

    ll ans = 0;
    ll res = 0;
    vi used(2*n);
    auto dfs = [&](auto self)->void{
        int ch = 0;
        rep(i,2*n)if(!used[i]){
            ch = i;
            break;
        }
        for(int j=ch+1; j<2*n;j++){
            if(a[ch][j]==-1) continue;
            if(used[ch] || used[j]) continue;
            res^=a[ch][j];
            used[ch] = 1;
            used[j] = 1;
            debug(res);
            if(accumulate(all(used),0)==2*n) chmax(ans,res);
            self(self);
            used[ch] = 0;
            used[j] = 0;
            res^=a[ch][j];
        }
    };
    dfs(dfs);

    cout << ans << endl;
}