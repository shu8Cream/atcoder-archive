/**
*    author:  shu8Cream
*    created: 18.09.2021 16:17:49
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

template<class T> inline bool chmax(T& a, T b) {
    if (a < b) { a = b; return true; }
    return false;
}
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) { a = b; return true; }
    return false;
}

const ll INF = 8e18;

struct edge {
    ll from, to, cost;
};

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

ll dist[3000];
// trueなら負閉路を含む
bool bellman_ford(vector<edge> &egs, int n, int s){
    rep(i,3000) dist[i] = INF;
    dist[s] = 0;
    int cnt = 0;
    while(cnt < n){
        bool end = true;
        for(auto e : egs){
            if(dist[e.from]!=INF && dist[e.from]+e.cost<dist[e.to]){
                dist[e.to] = dist[e.from] + e.cost;
                end = false;
            }
        }
        if(end) break;
        cnt++;
    }
    return (cnt==n);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m,p; cin >> n >> m >> p;
    vector<edge> eds(m);
    vvi to(n),rto(n);
    rep(i,m){
        int a,b,c; cin >> a >> b >> c;
        a--; b--;
        eds[i].from = a;
        eds[i].to = b;
        eds[i].cost = -1*(c-p);
        to[a].push_back(b);
        rto[b].push_back(a);
    }
    auto a = bfs(0, to);
    auto b = bfs(n-1, rto);
    set<ll> s,t;
    rep(i,n) if(a[i]!=-1) t.insert(i);
    rep(i,n) if(b[i]!=-1 && t.count(i)) s.insert(i);
    vector<edge> teds;
    set<ll> v;
    for(edge q : eds){
        if(!s.count(q.from) || !s.count(q.to)) continue;
        teds.push_back(q);
        v.insert(q.from);
        v.insert(q.to);
    }
    if(bellman_ford(teds, sz(v), 0)) cout << -1 << endl;
    else if(-1*dist[n-1]<0) cout << 0 << endl;
    else cout << -1*dist[n-1] << endl;
}