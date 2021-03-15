/**
*    author:  shu8Cream
*    created: 14.03.2021 20:42:04
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

const int mod = 998244353;

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
    int n;
    cin >> n;
    vi f(n);
    UnionFind uf(n);
    set<int> s;
    int cnt = 0;
    rep(i,n){
        cin >> f[i];
        f[i]--;
        uf.unite(i,f[i]);
    }
    rep(i,n) s.insert(uf.find(i));
    ll ans = 1;
    cnt = s.size();
    rep(i,cnt) ans = (ans + ans) % mod;
    ans-=1;
    cout << ans << endl;
}