/**
*    author:  shu8Cream
*    created: 14.03.2021 20:41:54
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

const vector<ll> prime = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> x(n);
    rep(i,n) cin >> x[i];
    set<ll> s;
    int ps = prime.size();
    rep(i,n){
        rep(j,prime.size()){
            if(x[i]%prime[j]==0) s.insert(prime[j]);
        }
    }
    int ss = s.size();
    vector<ll> cnt(ss);
    int i=0;
    for(auto p : s){
        cnt[i]=p;
        i++;
    }
    ll ans = 1e18;
    rep(b,1<<ss){
        ll tmp = 1;
        rep(i,ss){
            if(b>>i&1) tmp*=cnt[i];
        }
        bool f =true;
        rep(i,n){
            if(gcd(x[i],tmp)==1) f = false;
        }
        if(f) ans = min(ans,tmp);
    }
    cout << ans << endl;
}