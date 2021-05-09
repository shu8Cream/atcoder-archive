/**
*    author:  shu8Cream
*    created: 09.05.2021 21:59:52
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll k,n,m;
    cin >> k >> n >> m;
    vector<P> a(k), b(k);
    rep(i,k){
        ll p; cin >> p;
        a[i] = {p,i};
    }
    sort(rall(a));
    vector<P> vec(k);
    rep(i,k){
        ll e,idx;
        tie(e,idx) = a[i];
        ll p = floor(double(e*m/n));
        ll q = p*n - e*m;
        vec[i] = {q,idx};
        b[i] = {idx,p};
        // cerr << idx << " " << p << endl;
    }
    ll sum = 0;
    rep(i,k){
        ll e,idx;
        tie(idx,e) = b[i];
        sum+=e;
    }
    sort(all(vec));
    rep(i,k){
        ll e,idx;
        tie(e,idx) = vec[i];
        // printf("index:%d %d\n", idx,e);
    }
    sort(all(b));
    rep(i,m-sum){
        ll e,idx;
        tie(e,idx) = vec[i];
        b[idx].second++;
        // cerr << idx << endl;
    }
    for(auto [f,s] : b){
        cout << s << " ";
    }cout << endl;
}