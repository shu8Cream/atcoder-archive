/**
*    author:  shu8Cream
*    created: 11.09.2021 22:04:56
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

template<typename T>
struct edge {
    int from, to;
    T cost;
};

struct UnionFind{
    vector<int> par;
    vector<map<int, int>> mp;
    UnionFind(int n=0): par(n, -1), mp(n) {}
    int find(int x){
        if(par[x] < 0) return x;
        return par[x] = find(par[x]);
    }
    bool merge(int x, int y){
        x = find(x); y = find(y);
        if(x == y) return false;
        if(par[x] > par[y]) swap(x,y);
        for(auto p : mp[y]){
            mp[x][p.first] += p.second;
        }
        mp[y] = map<int,int>();
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    bool same(int x, int y) {return find(x) == find(y);}
    int size(int x) {return -par[find(x)];}
};

template<typename T>
T kruskal(vector<edge<T>> &edges, int v){
    sort(all(edges), [](const edge<T> &a, const edge<T> &b) {
        return a.cost < b.cost;
    });
    UnionFind uf(v);
    T res = 0;
    for(edge<T> &e : edges){
        if(!uf.same(e.to, e.from)){
            res += e.cost;
            uf.merge(e.to, e.from);
        }else if(e.cost<0){
            res += e.cost;
            uf.merge(e.to, e.from);
        }
    }
    return res;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    vector<edge<ll>> vec(m);
    ll sum = 0;
    rep(i,m){
        int s,t; ll w; cin >> s >> t >> w;
        s--; t--;
        vec[i] = {s,t,w};
        sum += w;
    }
    ll ans = kruskal(vec,n);
    ans = sum - ans; 
    cout << ans << endl;
}