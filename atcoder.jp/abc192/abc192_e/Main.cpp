/**
*    author:  shu8Cream
*    created: 27.02.2021 15:20:00
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

const ll INF = 1e18+5;
const int MAX_V = 100100;

struct edge { ll to, cost, dpt; };

ll V, d[MAX_V]; //dはコスト配列
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
            if(d[v]%e.dpt==0){
                if (d[e.to] > d[v] + e.cost) {
                    d[e.to] = d[v] + e.cost;
                    que.push(P(d[e.to], e.to));
                }
                //cerr << 1 << endl;
                //cerr << d[e.to] << " " << e.to+1 << endl;
            }else{
                if (d[e.to] > d[v] + e.cost + (e.dpt-d[v]%e.dpt)) {
                    d[e.to] = d[v] + e.cost + (e.dpt-d[v]%e.dpt);
                    que.push(P(d[e.to], e.to));
                }
                //cerr << 2 << endl;
                //cerr << d[e.to] << " " << e.to+1 << endl;
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m,x,y;
    cin >> n >> m >> x >> y;
    x--; y--;
    rep(i,m){
        ll a,b,t,k;
        cin >> a >> b >> t >> k;
        a--; b--;
        G[a].push_back((edge){b,t,k});
        G[b].push_back((edge){a,t,k});
    }
    dijkstra(x);
    if(d[y]==INF) cout << -1 << endl;
    else cout << d[y] << endl;
}