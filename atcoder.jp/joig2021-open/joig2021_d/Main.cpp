/**
*    author:  shu8Cream
*    created: 29.04.2021 14:50:12
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

int n,m,d;
vector<P> xv;

bool check(ll mid){
    ll cnt = 0, pre = -1e9;
    rep(i,n){
        ll x,v; tie(x,v) = xv[i]; 
        if (v<mid || x-pre<d) continue;
        cnt++; pre = x;
    }
    if (cnt < m) return false;
    return true;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m >> d;
    vi x(n),v(n);
    xv.resize(n);
    rep(i,n){
        ll a,b; cin >> a >> b;
        x[i]=a; v[i]=b;
        xv[i] = {a,b};
    }
    sort(all(xv));
    ll ok = -1, ng = 8e9;
    while(ng-ok>1){
        ll mid = (ok + ng) / 2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
}