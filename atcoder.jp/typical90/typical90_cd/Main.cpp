/**
*    author:  shu8Cream
*    created: 11.07.2021 15:37:17
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=(n-1); i>=0; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
using ull = unsigned long long;
using P = pair<ll,ll>;
using vi = vector<ull>;
using vvi = vector<vi>;

template<class T> inline bool chmax(T& a, T b) {
    if (a < b) { a = b; return true; }
    return false;
}
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) { a = b; return true; }
    return false;
}

const int mod = 1000000007;
//const int mod = 998244353;
struct mint{
    ll x; // typedef long long ll;
    mint(ull x=0):x((x%mod+mod)%mod){}
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
    mint pow(ull t) const {
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

mint f(ull x){
    mint res = x%mod*((x+1)%mod);
    res/=2;
    return res;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ull l,r; cin >> l >> r;
    vi pow10(22); pow10[0]=1;
    rep(i,20) pow10[i+1]=pow10[i]*10;
    mint ans = 0;
    rep(i,19){
        ull vl = max(l,pow10[i]);
        ull vr = min(r,pow10[i+1]-1);
        if(vl>vr) continue;
        // cerr << vl << " " << vr << endl;
        mint val = f(vr) - f(vl-1);
        ans += (mint)(i+1)*val;
    }
    cout << ans << endl;
}