/**
*    author:  shu8Cream
*    created: 03.05.2021 21:02:38
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

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
    Sieve sieve(20000000);
    int n,k;
    cin >> n >> k;
    int ans = 0;
    for(int i=2; i<=n; i++){
        if(sieve.factor(i).size()>=k) ans++;
    }
    cout << ans << endl;
}