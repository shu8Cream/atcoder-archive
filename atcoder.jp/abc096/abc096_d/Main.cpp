/**
*    author:  shu8Cream
*    created: 19.08.2021 18:49:17
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

    vector<int> prime(){
        return primes;
    }
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    Sieve sieve(100000);
    int n; cin >> n;
    vi a;
    auto pri = sieve.prime();
    for(auto p : pri){
        if(p%5==1) a.push_back(p);
        if(a.size()==n) break;
    }
    rep(i,n) cout << a[i] << " ";
    cout << endl;
}