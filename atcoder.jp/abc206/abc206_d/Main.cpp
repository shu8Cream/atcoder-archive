/**
*    author:  shu8Cream
*    created: 20.06.2021 13:23:51
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
    int n; cin >> n;
    vi a(n); rep(i,n) cin >> a[i];
    UnionFind uf(n);
    rep(i,n/2){
        if(a[i]==a[n-1-i]) continue;
        uf.merge(i,n-1-i);
    }
    map<ll,vi> m;
    rep(i,n) m[a[i]-1].push_back(i);
    for(auto [k,vec] : m){
        rep(i,vec.size()-1) uf.merge(vec[i],vec[i+1]);
    }
    set<ll> rem;
    ll ans = 0;
    vi pa(n);
    vector<set<ll>> kk(n);
    rep(i,n) pa[i] = uf.find(i);
    rep(i,n) kk[pa[i]].insert(a[i]);
    rep(i,n/2){
        if(a[i]==a[n-1-i]) continue;
        if(rem.count(uf.find(i))) continue;
        rem.insert(uf.find(i));
        if(kk[pa[i]].empty()) continue;
        ans += kk[pa[i]].size() - 1;
    }
    cout << ans << endl;
}