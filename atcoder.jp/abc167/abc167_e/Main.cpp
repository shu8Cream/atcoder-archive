/**
*    author:  shu8Cream
*    created: 13.04.2021 21:38:36
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
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

ll mod_pow(ll a, ll b, ll n){
    if(b==0) return 1;
    if(b%2!=0) return a * mod_pow(a, b-1, n) % n;
    else return mod_pow(a * a % n, b / 2, n) % n;
}

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
    ll n,m,k;
    cin >> n >> m >> k;
    mint ans = 0;
    rep(i,k+1){
        mint tmp = m * mod_pow(m-1,n-1-i,mod);
        ans+=tmp*nCk(n-1,i);
    }
    cout << ans << endl;
}