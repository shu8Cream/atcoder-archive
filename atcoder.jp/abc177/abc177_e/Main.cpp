/**
*    author:  shu8Cream
*    created: 26.02.2021 14:56:03
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

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
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vi a(n);
    rep(i,n) cin >> a[i];
    Sieve sieve(1e6);
    bool pair = true;
    map<int,int> mp;
    rep(i,n){
        auto f = sieve.factor(a[i]);
        for(auto p : f){
            if(mp.count(p.first)) pair = false;
            mp[p.first] = p.second;
        }
    }

    bool set = false;
    int g=a[0];
    rep(i,n){
        g=gcd(g,a[i]);
    }
    if(g==1) set = true;

    if(pair) cout << "pairwise coprime" << endl;
    else if(set) cout << "setwise coprime" << endl;
    else cout << "not coprime" << endl;
}