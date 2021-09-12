/**
*    author:  shu8Cream
*    created: 12.09.2021 01:34:52
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

ll bfs(int n, vvi &to){
    vi dist(n,-1);
    queue<int> q;
    dist[0] = 0;
    q.push(0);
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(auto nv : to[v]){
            if(dist[nv]!=-1) continue;
            dist[nv] = dist[v] + 1;
            q.push(nv);
        }
    }
    return dist[n-1];
}

vi path(int n, vvi &to){
    vi dist(n,-1);
    vi prev(n,-1);
    queue<int> q;
    dist[0] = 0;
    q.push(0);
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(auto nv : to[v]){
            if(dist[nv]!=-1) continue;
            dist[nv] = dist[v] + 1;
            prev[nv] = v;
            q.push(nv);
        }
    }
    vi walk(dist[n-1]+1,-1);
    rrep(i,n){
        if(dist[i]<=0) continue;
        if(walk[dist[i]-1]!=-1) continue;
        walk[dist[i]-1] = prev[i];
    }
    walk[dist[n-1]] = n-1;
    return walk;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    vvi to(n);
    vector<P> edge(m);
    rep(i,m){
        int s,t; cin >> s >> t;
        s--; t--;
        to[s].push_back(t);
        edge[i] = {s,t};
    }
    
    if(bfs(n,to)==-1){
        rep(i,m) cout << -1 << endl;
        return 0;
    }
    vi walk = path(n,to);
    vi ans(m,bfs(n,to));
    rep(i,sz(walk)-1){
        vvi tto(n);
        int idx = -1;
        rep(j,m){
            int a,b;
            tie(a,b) = edge[j];
            if(a==walk[i] && b==walk[i+1]){
                idx = j;
                continue;
            }
            tto[a].push_back(b);
        }
        if(idx!=-1) ans[idx] = bfs(n,tto);
    }

    rep(i,m) cout << ans[i] << endl;
}