/**
*    author:  shu8Cream
*    created: 01.07.2021 23:07:53
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

vector<P> prime_fact(ll n){
    vector<P> res;
    for(ll i=2; i*i<=n; i++){
        if(n%i!=0) continue;
        ll ex = 0;
        while(n%i==0){
            ex++;
            n/=i;
        }
        res.push_back({i,ex});
    }
    if(n!=1) res.push_back({n,1});
    return res;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    auto res = prime_fact(n);
    ll cnt = 0;
    for(auto [f,s] : res){
        cnt+=s;
    }
    cout << ceil(log2(cnt)) << endl;
}