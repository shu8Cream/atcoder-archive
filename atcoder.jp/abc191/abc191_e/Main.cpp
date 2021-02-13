/**
*    author:  shu8Cream
*    created: 10.02.2021 15:49:48
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;

const int INF = 1e9+1;
const int MAX_V = 2010;

struct edge { int to, cost; };

void dijkstra(const vector<edge>* A, int s, vi& d) { //始点を与える
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
        for (auto e : A[v]) {
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
    vector<edge> G1[MAX_V];
    vector<edge> G2[MAX_V];
    vi roop(n,INF);
    rep(i,m) {
        int a,b,c;
        cin >> a >> b >> c;
        --a, --b;
        G1[a].push_back((edge){b,c});
        G2[b].push_back((edge){a,c});
        if(a==b) roop[a]=min(roop[a], c);
    }
    vi d1(MAX_V);
    vi d2(MAX_V);
    rep(i,n){
        int ans = INF;
        dijkstra(G1,i,d1);
        dijkstra(G2,i,d2);
        rep(j,n){
            if(i==j) continue;
            if(d1[j]==INF || d2[j]==INF) continue;
            ans=min(ans, d1[j]+d2[j]);
        }
        if(roop[i]!=INF) ans=min(ans, roop[i]);
        if(ans==INF) cout << -1 << endl;
        else cout << ans << endl;
    }
}