/**
*    author:  shu8Cream
*    created: 04.05.2021 22:24:32
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

ll n,k;

bool check(ll mid, vi &a){
    ll cnt = k;
    rep(i,n){
        if(mid<a[i]) cnt-=a[i]/mid;
    }
    if(cnt<0) return true;
    return false;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    vi a(n); rep(i,n) cin >> a[i];
    ll ok = 1, ng = 1001001001;
    while(ng-ok>1){
        ll mid = (ng + ok) / 2;
        if(check(mid,a)) ok = mid;
        else ng = mid;
    }
    if(ok!=1) ok++;
    cout << ok << endl;
}