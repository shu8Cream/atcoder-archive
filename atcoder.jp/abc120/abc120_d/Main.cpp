/**
*    author:  shu8Cream
*    created: 28.04.2021 22:44:02
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

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
        if(par[x] > par[y]) swap(x,y); //マージテク
        for(auto p : mp[y]){
            mp[x][p.first] += p.second;
        }
        mp[y] = map<int,int>(); //メモリの解放
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    bool same(int x, int y) {return find(x) == find(y);}
    int size(int x) {return -par[find(x)];}
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,m;
    cin >> n >> m;
    vector<P> path(m);
    rep(i,m){
        int a,b; cin >> a >> b;
        a--; b--;
        path[i] = {a,b};
    }
    reverse(all(path));
    UnionFind uf(n);
    ll all = n*(n-1)/2;
    vi ans(m);
    rep(i,m){
        ans[i] = all;
        int x,y;
        tie(x,y) = path[i];
        if(uf.same(x,y)) continue;
        all -= uf.size(x)*uf.size(y);
        uf.merge(x,y);
    }
    reverse(all(ans));
    rep(i,m) cout << ans[i] << endl;
}