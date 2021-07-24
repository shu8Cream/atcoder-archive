/**
*    author:  shu8Cream
*    created: 24.07.2021 21:34:45
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

const ll INF = 1e18+20;
const int MAX_V = 200100;
const int mod = 1e9+7;

struct edge { int to, cost; };

ll V, d[MAX_V],cnt[MAX_V]; //dはコスト配列
vector<edge> G[MAX_V]; //辺とコストを受け取るグラフ

void dijkstra(int s) { //始点を与える
    rep (i,MAX_V) d[i] = INF;
    d[s] = 0;
    rep (i,MAX_V) cnt[i] = 0;
    cnt[s] = 1;
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
                cnt[e.to] = cnt[v];
            }else if(d[e.to] == d[v] + e.cost) {
                cnt[e.to] += cnt[v];
                cnt[e.to] %= mod;
            }
        }
    }
}

int main(){
    int v,e; cin >> v >> e;
    rep(i,e){
        int a,b; cin >> a >> b;
        a--; b--;
        G[a].push_back((edge){b,1});
        G[b].push_back((edge){a,1});
    }
    dijkstra(0);
    cout << cnt[v-1] << endl;
}