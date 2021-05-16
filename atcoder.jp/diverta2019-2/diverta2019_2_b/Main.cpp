/**
*    author:  shu8Cream
*    created: 16.05.2021 14:00:44
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
    vi x(n), y(n);
    map<P,ll> ball;
    rep(i,n){
        cin >> x[i] >> y[i];
        ball[{x[i],y[i]}]=i;
    }
    ll ans = 1000;
    rep(i,n)for(int j=i+1; j<n; j++){
        ll p = x[j]-x[i];
        ll q = y[j]-y[i];
        UnionFind uf(n);
        rep(k,n){
            ll nx = x[k], ny = y[k]; 
            if(ball.count({nx-p,ny-q})) uf.merge(k,ball[{nx-p,ny-q}]);
            if(ball.count({nx+p,ny+q})) uf.merge(k,ball[{nx+p,ny+q}]);
        }
        set<ll> groups;
        rep(k,n) groups.insert(uf.find(k));
        ll res = groups.size();
        chmin(ans, res);
    }
    if(ans==1000) ans = 1;
    cout << ans << endl;
}