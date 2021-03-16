/**
*    author:  shu8Cream
*    created: 22.02.2021 00:37:07
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
struct mint{
    ll x;
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

mint upper[220000];
mint lower[220000];
mint lower2[220000];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m,k;
    cin >> n >> m >> k;
    if(n>m) swap(n,m);
    if(n==1){
        cout << mint(k).pow(m) << endl;
        return 0;
    } 
    for(int x=1; x<=k; x++)
        upper[x] = mint(k-x+1).pow(m);
    for(int x=1; x<=k; x++)
        lower[x] = mint(x).pow(n);
    for(int x=1; x<=k; x++)
        lower2[x] = lower[x] - lower[x-1];

    mint ans = 0;
    for(int x=1; x<=k; x++)
        ans+=lower2[x]*upper[x];
    cout << ans << endl;
}