/**
*    author:  shu8Cream
*    created: 27.11.2021 21:16:14
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
const ll INF = 8e18;

template<class T> inline bool chmax(T& a, T b) {
    if (a < b) { a = b; return true; }
    return false;
}
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) { a = b; return true; }
    return false;
}

void debug_out() { cout << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
cout << H << " ";
debug_out(T...);
}

#ifdef _DEBUG
#define debug(...) debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

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
    int n,m; cin >> n >> m; 
    UnionFind uf(n);
    vector<P> ab(m);
    rep(i,m){
        int a,b; cin >> a >> b;
        a--; b--;
        ab[i] = {a,b};
    }
    sort(rall(ab));
    vi ans(n);
    int cur = 0;
    set<int> se;
    rrep(i,n){
        while(1){
            if(cur>=m) break;
            auto [a,b] = ab[cur];
            if(a<=i || b<=i) break;
            int apar = uf.find(a);
            int bpar = uf.find(b);
            debug("q", apar+1, bpar+1);
            cur++;
            if(apar==bpar) continue;
            uf.merge(a,b);
            debug("n",uf.find(a)+1, sz(se));
            if(apar==uf.find(a) && se.count(bpar)) se.erase(bpar);
            if(bpar==uf.find(a) && se.count(apar)) se.erase(apar);
        }
        ans[i] = se.size();
        se.insert(i);
    }
    rep(i,n) cout << ans[i] << endl;
}