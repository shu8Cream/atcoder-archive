/**
*    author:  shu8Cream
*    created: 24.12.2020 21:43:17
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;

const int mod = 1e9+7;
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

int main() {
    Sieve sieve(1e6);
    int n;
    cin >> n;
    map<int,int> mp;
    ll ans=1;
    rep(i,n){
        auto fl = sieve.factor(i+1);
        for(auto p : fl){
            mp[p.first]+=p.second;
        }
    }
    for(auto p : mp){
        ans=(ans*(p.second+1))%mod;
    }
    cout << ans << endl;
}