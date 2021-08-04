/**
*    author:  shu8Cream
*    created: 03.08.2021 19:23:50
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

struct Sieve{
    int n;
    vector<int> f,primes;
    Sieve(int n=1):n(n+1),f(n+1){
        f[0] = f[1] = -1;
        for(ll i=2; i<=n; ++i){
            if(f[i]) continue;
            primes.push_back(i);
            f[i]=i;
            for(ll j=i*i; j<=n; j+=i){
                if(!f[j]) f[j]=i;
            }
        }
    }

    bool isPrime(int x){ return f[x]==x;}

    vector<int> factorList(int x){
        vector<int> res;
        while(x!=1){
            res.push_back(f[x]);
            x/=f[x];
        }
        return res;
    }

    vector<P> factor(int x){
        vector<int> fl = factorList(x);
        if(fl.size()==0) return {};
        vector<P> res(1,P(fl[0], 0));
        for(int p : fl){
            if(res.back().first == p){
                res.back().second++;
            }else{
                res.emplace_back(p,1);
            }
        }
        return res;
    }
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    Sieve sieve(15001000);
    int n; cin >> n;
    vi a(n); rep(i,n) cin >> a[i];
    vi l(n+2),r(n+2);
    rep(i,n) l[i+1] = gcd(l[i],a[i]);
    rrep(i,n) r[i+1] = gcd(r[i+2],a[i]);
    ll ans = 0;
    rep(i,n) chmax(ans, gcd(l[i],r[i+2]));
    cout << ans << endl;
}