/**
*    author:  shu8Cream
*    created: 19.02.2022 21:17:44
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
    int n,q; cin >> n >> q;
    vi x(n); rep(i,n) cin >> x[i];
    vvi to(n);
    rep(i,n-1){
        int a,b; cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    using Q = priority_queue<ll, vi, greater<ll>>;
    vector<Q> sets(n);
    auto dfs = [&](auto dfs, int s, int p=-1)->void{
        if(s!=0 && sz(to[s])==1){
            sets[s].push(x[s]);
            return;
        }
        for(auto v:to[s]){
            if(v==p) continue;
            dfs(dfs,v,s);
            vi tmp;
            if(!sets[v].empty()){
                while(!sets[v].empty()){
                    auto e = sets[v].top(); sets[v].pop();
                    sets[s].push(e);
                    tmp.push_back(e);
                }
            }
            for(auto e:tmp) sets[v].push(e);
            while(sz(sets[s])>20){
                sets[s].pop();
            }
        }
        sets[s].push(x[s]);
        return;
    };
    dfs(dfs,0);
    // rep(i,n){
    //     vi tmp;
    //     while(!sets[i].empty()){
    //         auto e = sets[i].top();
    //         cout << e << " ";
    //         sets[i].pop();
    //         tmp.push_back(e);
    //     }
    //     for(auto e:tmp) sets[i].push(e);
    //     cout << endl;
    // }

    rep(i,q){
        int v,k; cin >> v >> k; v--;
        vi tmp;
        debug("size:", sz(sets[v]));
        while(sz(sets[v])>k){
            auto e = sets[v].top(); sets[v].pop();
            tmp.push_back(e);
        }
        cout << sets[v].top() << endl;
        for(auto e:tmp) sets[v].push(e);
    }
}