/**
*    author:  shu8Cream
*    created: 03.01.2021 22:52:17
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

struct UnionFind{
    vector<int> par;
    vector<map<int, int>> mp;
    UnionFind(int n=0): par(n, -1), mp(n) {}
    int find(int x){
        if(par[x] < 0) return x;
        return par[x] = find(par[x]);
    }
    bool unite(int x, int y){
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

    int n,m,k;
    cin >> n >> m >> k;
    UnionFind uf(n);
    vi fb(n);

    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--;b--;
        uf.unite(a,b);
        fb[a]++;
        fb[b]++;
    }

    rep(i,k){
        int c,d;
        cin >> c >> d;
        c--;d--;
        if(uf.same(c,d)){
            fb[c]++;
            fb[d]++;       
        }
    }
    vi ans(n);
    rep(i,n){
        ans[i]=uf.size(i)-1-fb[i];
    }
    rep(i,n) cout << ans[i] << endl;
}