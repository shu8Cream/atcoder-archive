/**
*    author:  shu8Cream
*    created: 26.12.2020 09:20:23
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;

const int MX = 1000005;

struct Sieve {
    int n;
    vector<int> f, primes;
    Sieve(int n=1):n(n+1), f(n+1) {
        f[0] = f[1] = -1;
        for(ll i=2; i <= n; ++i){
            if(f[i]) continue;
            primes.push_back(i);
            f[i]=i;
            for(ll j=i*i; j <= n; j+=i){
                if(!f[j]) f[j]=i;
            }
        }
    }
    bool isPrime(int x){ return f[x] == x;}
    //xの素因数分解の要素の配列
    vector<int> factorList(int x){
        vector<int> res;
        while(x != 1){
            res.push_back(f[x]);
            x /= f[x];
        }
        return res;
    }
    //xの素因数分解の要素をRunLength圧縮
    vector<P> factor(int x){
        vector<int> fl = factorList(x);
        if(fl.size() == 0) return {};
        vector<P> res(1, P(fl[0], 0));
        for(int p:fl){
            if(res.back().first == p){
                res.back().second++;
            } else {
                res.emplace_back(p, 1);
            }
        }
        return res;
    }
};

const int mod = 1e9+7;

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

int main() {
    Sieve sieve(1e6);
    int n;
    cin >> n;
    vi a(n);
    rep(i,n) cin >> a[i];

    map<int,int> mp;
    rep(i,n){
        auto f = sieve.factor(a[i]);
        for(auto p : f){
            mp[p.first] = max(mp[p.first], p.second);
        }
    }

    mint lcm = 1;
    for(auto p : mp){
        rep(i,p.second) lcm*=p.first;
    }

    mint ans = 0;
    rep(i,n){
        mint b = lcm/a[i];
        ans=(ans+b);
    }

    cout << ans << endl;
}