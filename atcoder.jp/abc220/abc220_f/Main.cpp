/**
*    author:  shu8Cream
*    created: 26.09.2021 21:44:11
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

void debug_out() { cout << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
cout << H << " ";
debug_out(T...);
}

#ifdef _DEBUG
#define debug(...) debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

ll child[200100];
ll ans[200100];

void dfs(int s, vvi &to, int pre=-1) {
    child[s] = 1;
    for(int nv : to[s]){
        if(nv==pre) continue;
        dfs(nv,to,s);
        child[s] += child[nv];
    }
}

vi bfs(int s, vvi &to){
    int n = sz(to);
    vi dist(n, -1);
    queue<int> q;
    dist[s] = 0;
    q.push(s);

    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int nv : to[v]) {
            if (dist[nv] != -1) continue;
            dist[nv] = dist[v] + 1;
            q.push(nv);
        }
    }
    return dist;
}

void dfs2(int s, vvi &to, ll dis, int pre=-1){
    int n = sz(to);
    ans[s] = dis;
    for(int e : to[s]){
        if(e==pre) continue;
        ans[e] = ans[s]+n-2*child[e];
        dfs2(e,to,ans[e],s);
    }
}

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
    dfs(0,to);
    auto dis = bfs(0,to);
    ll sum = 0;
    rep(i,sz(dis)) sum+=dis[i];
    dfs2(0,to,sum);
    rep(i,n) cout << ans[i] << endl;
}