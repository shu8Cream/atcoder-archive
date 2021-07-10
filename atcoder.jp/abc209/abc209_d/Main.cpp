/**
*    author:  shu8Cream
*    created: 10.07.2021 20:41:14
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=(n-1); i>=0; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

template<class T> inline bool chmax(T& a, T b) {
    if (a < b) { a = b; return true; }
    return false;
}
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) { a = b; return true; }
    return false;
}

using Graph = vvi;

struct LCA{
    vvi parent;
    vi dist;
    LCA(const Graph &G, int root = 0){ init(G,root); }

    void init(const Graph &G, int root = 0){
        int V = G.size();
        int k = 1;
        while((1<<k) < V) k++;
        parent.assign(k,vi(V,-1));
        dist.assign(V,-1);
        dfs(G, root, -1, 0);
        rep(i,parent.size()-1)rep(j,V){
            if(parent[i][j]!=-1) parent[i+1][j]=parent[i][parent[i][j]];
        }
    }

    void dfs(const Graph &G, int v, int p, int d){
        parent[0][v]=p;
        dist[v]=d;
        for(auto e : G[v]) if(e!=p) dfs(G,e,v,d+1);
    }

    int query(int u, int v){
        if(dist[u] < dist[v]) swap(u,v);
        int k = parent.size();
        rep(i,k){
            if((dist[u]-dist[v]) >> i & 1){
                u = parent[i][u];
            }
        }
        if(u==v) return u;
        for(int i=k-1; i>=0; i--){
            if(parent[i][u] != parent[i][v]){
                u = parent[i][u];
                v = parent[i][v];
            }
        }
        return parent[0][u];
    }

    int get_dist(int u, int v) { 
        return dist[u] + dist[v] - 2 * dist[query(u, v)];
    }

    bool is_on_path(int u, int v, int a) {
        return get_dist(u, a) + get_dist(a, v) == get_dist(u, v);
    }
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,Q; cin >> n >> Q;
    Graph to(n);
    rep(i,n-1){
        ll a,b; cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    vi dist(n,-1);
    queue<ll> q;
    dist[0] = 0;
    q.push(0);
    while(!q.empty()){
        ll v = q.front(); q.pop();
        for(auto nv : to[v]){
            if(dist[nv]!=-1) continue;
            dist[nv] = dist[v] + 1;
            q.push(nv);
        }
    }
    LCA lca(to);
    rep(i,Q){
        ll c,d; cin >> c >> d;
        c--; d--;
        ll t  = lca.query(c,d);
        ll dis = dist[c]-dist[t] + dist[d]-dist[t];
        cout << (dis%2==1 ? "Road" : "Town") << endl;
    }
}