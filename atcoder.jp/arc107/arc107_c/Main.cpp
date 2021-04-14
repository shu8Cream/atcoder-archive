/**
*    author:  shu8Cream
*    created: 14.04.2021 21:26:02
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (ll i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

const int mod = 998244353;
struct mint{
    ll x; // typedef long long ll;
    mint(ll x=0):x((x%mod+mod)%mod){}
    mint operator-() const { return mint(-x);}
    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += mod-a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
    mint operator+(const mint a) const { return mint(*this) += a;}
    mint operator-(const mint a) const { return mint(*this) -= a;}
    mint operator*(const mint a) const { return mint(*this) *= a;}
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }

    // for prime mod
    mint inv() const { return pow(mod-2);}
    mint& operator/=(const mint a) { return *this *= a.inv();}
    mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

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
    int n,k;
    cin >> n >> k;
    vvi a(n,vi(n));
    rep(i,n)rep(j,n) cin >> a[i][j];
    UnionFind ufr(n), ufc(n);
    rep(j,n)rep(l,n){
        if(j==l) continue;
        bool f = false;
        rep(i,n){
            if(a[i][j]+a[i][l]>k){
                f = true;
            }
        }
        if(f) continue;
        ufr.merge(j,l);
    }
    rep(j,n)rep(l,n){
        if(j==l) continue;
        bool f = false;
        rep(i,n){
            if(a[j][i]+a[l][i]>k){
                f = true;
            }
        }
        if(f) continue;
        ufc.merge(j,l);
    }

    vi rr(n+1),cc(n+1);
    rep(i,n) rr[ufr.find(i)]++;
    rep(i,n) cc[ufc.find(i)]++;
    mint n1 = 1, n2 = 1;
    for(auto p : rr){
        rep(i,p) n1*=i+1;
    }
    for(auto p : cc){
        rep(i,p) n2*=i+1;
    }
    mint ans = n1*n2;
    cout << ans << endl;
}