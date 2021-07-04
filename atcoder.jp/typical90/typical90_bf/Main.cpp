/**
*    author:  shu8Cream
*    created: 03.07.2021 23:31:14
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

const int mod = 100000;

ll digit_sum(ll n){
    ll res = n%10;
    while(n/=10) res+=n%10;
    return res;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,k; cin >> n >> k;
    set<ll> s; vi a,b;
    s.insert(n); a.push_back(n);
    ll tmp = (n + digit_sum(n))%mod;
    while(!s.count(tmp)){
        s.insert(tmp);
        a.push_back(tmp);
        tmp = (tmp + digit_sum(tmp))%mod;
    }
    ll bLoop = 0, T = 0;
    bool f = false;
    rep(i,a.size()){
        if(tmp==a[i]) f = true;
        if(f) b.push_back(a[i]);
        else bLoop++; 
    } 
    T = a.size() - bLoop;
    if(k<bLoop) cout << a[k] << endl;
    else cout << b[(k-bLoop)%T] << endl;
}