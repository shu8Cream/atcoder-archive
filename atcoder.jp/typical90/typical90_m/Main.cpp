/**
*    author:  shu8Cream
*    created: 13.04.2021 10:26:30
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

const int INF = 1e9+1;
const int MAX_V = 100100;

struct edge { int to, cost; };

int V, d[MAX_V]; //dはコスト配列
vector<edge> G[MAX_V]; //辺とコストを受け取るグラフ

void dijkstra(int s) { //始点を与える
    rep (i,MAX_V) d[i] = INF;
    d[s] = 0;
    // 小さい順に取り出される優先度付きキュー
    priority_queue<P, vector<P>, greater<P>> que;
    que.push(P(0, s));
    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        for (auto e : G[v]) {
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    rep(i,m){
        int a,b,c;
        cin >> a >> b >> c;
        a--; b--;
        G[a].push_back((edge){b,c});
        G[b].push_back((edge){a,c});
    }
    dijkstra(0);
    vi ans(n);
    rep(i,n) ans[i]+=d[i];
    dijkstra(n-1);
    rep(i,n) ans[i]+=d[i];
    rep(i,n) cout << ans[i] << endl;
}