/**
*    author:  shu8Cream
*    created: 14.09.2021 18:49:28
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
const int MAX_V = 100100;

struct edge { int to; ll cost; };

ll d[MAX_V];
vector<edge> G[MAX_V];

//始点を与える
void dijkstra(int s) {
    rep (i,MAX_V) d[i] = INF;
    d[s] = 0;
    priority_queue<P, vector<P>, greater<P>> q;
    q.push(P(0, s));
    while (!q.empty()) {
        P p = q.top();
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
    int n; cin >> n;
    rep(i,n-1){
        int u,v; ll w; cin >> u >> v >> w;
        u--; v--;
        G[u].push_back((edge){v,w});
        G[v].push_back((edge){u,w});
    }
    dijkstra(0);
    rep(i,n) cout << d[i]%2 << endl;
}