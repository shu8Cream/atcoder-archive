/**
*    author:  shu8Cream
*    created: 20.02.2022 20:46:47
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
    vvi to(n);
    rep(i,n-1){
        int u,v; cin >> u >> v;
        u--; v--;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    vector<P> ans(n,{INF,0LL});
    ll cnt = 1;
    auto dfs = [&](auto dfs, int s, int p=-1)->void{
        if(sz(to[s])==1 && s!=0){
            ans[s] = {cnt,cnt};
            cnt++;
            return;
        }
        for(auto v:to[s]){
            if(v==p) continue;
            dfs(dfs,v,s);
            chmin(ans[s].first,ans[v].first);
            chmax(ans[s].second,ans[v].second);
        }
    };
    dfs(dfs,0);
    rep(i,n) cout << ans[i].first << " " << ans[i].second << endl;
}