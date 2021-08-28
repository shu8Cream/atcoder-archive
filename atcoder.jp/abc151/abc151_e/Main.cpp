/**
*    author:  shu8Cream
*    created: 28.08.2021 13:44:53
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

const int mod = 1000000007;
//const int mod = 998244353;
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

mint fact[200200];
mint invfact[200200];

void init(){
    fact[0]=1;
    for(int i=1; i<200200; i++){
        fact[i]=fact[i-1]*i;
    }
    invfact[200200-1] = fact[200200-1].inv();
    for(int i=200200-2; i>=0; i--){
        invfact[i] = invfact[i+1]*(i+1);
    }
}

mint nCk(int n, int k){
    if(k<0 || n<k) return 0;
    return fact[n] * invfact[n-k] * invfact[k];
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    init();
    int n,k; cin >> n >> k;
    vi a(n); rep(i,n) cin >> a[i];
    sort(rall(a));
    mint ans = 0;
    rep(i,n-k+1){
        ans += (mint)a[i]*nCk(n-1-i,k-1);
    }
    sort(all(a));
    rep(i,n-k+1){
        ans -= (mint)a[i]*nCk(n-1-i,k-1);
    }
    cout << ans << endl;
}