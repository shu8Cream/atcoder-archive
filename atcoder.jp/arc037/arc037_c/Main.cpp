/**
*    author:  shu8Cream
*    created: 28.03.2021 13:38:11
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<ll>;
using vvi = vector<vi>;

int n,k;
vi a,b;
bool check(ll x){
    ll res = 0;
    rep(i,n){
        ll t = x / a[i];
        auto itr = upper_bound(all(b), t) - b.begin();
        res+=itr;  
    }
    if(res<k) return true;
    else return false;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    a.resize(n);
    b.resize(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    sort(all(a));
    sort(all(b));
    ll ng = 5e18, ok = -1;
    while(ng-ok>0){
        ll mid = (ng + ok) / 2;
        if(check(mid)) ok = mid+1;
        else ng = mid;
    }
    cout << ok << endl;
}