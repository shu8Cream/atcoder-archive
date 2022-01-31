/**
*    author:  shu8Cream
*    created: 30.01.2022 21:21:49
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

const int MAX_V = 200100;

struct edge { int to; ll cost; };

ll d[MAX_V];
vector<edge> G[MAX_V];

//始点を与える
void dijkstra(int s) {
    rep (i,MAX_V) d[i] = INF;
    d[s] = 0;
    queue<P> q;
    q.push(P(0, s));
    while (!q.empty()) {
        P p = q.front();
        q.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        for (auto e : G[v]) {
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                q.push(P(d[e.to], e.to));
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    vi h(n); rep(i,n) cin >> h[i];
    rep(i,m){
        int s,t; cin >> s >> t;
        s--; t--;
        if(h[s]<h[t]) swap(s,t);
        ll w = abs(h[s]-h[t]);
        G[s].push_back((edge){t,0});
        G[t].push_back((edge){s,w});
    }
    dijkstra(0);
    ll ans = 0;
    rep(i,n) chmax(ans,-d[i]-h[i]+h[0]);
    cout << ans << endl;
}