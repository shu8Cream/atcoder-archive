/**
*    author:  shu8Cream
*    created: 14.09.2021 22:33:43
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

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vvi to(3*n);
    rep(i,m){
        int u,v; cin >> u >> v;
        u--; v--;
        u*=3; v*=3;
        to[u].push_back(v+1);
        to[u+1].push_back(v+2);
        to[u+2].push_back(v);
    }
    int s,t; cin >> s >> t; 
    s--; t--;
    vi dist(3*n,-1);
    queue<int> q;
    dist[s*3] = 0;
    q.push(s*3);
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(auto nv : to[v]){
            if(dist[nv]!=-1) continue;
            dist[nv] = dist[v] + 1;
            q.push(nv);
        }
    } 
    cout << (dist[t*3]!=-1 ? dist[t*3]/3 : -1) << endl; 
}