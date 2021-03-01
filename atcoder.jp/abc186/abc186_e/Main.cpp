/**
*    author:  shu8Cream
*    created: 19.12.2020 21:08:58
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;

tuple<ll, ll, ll> extgcd(ll a, ll b){
    if(a == 0) return {0, 1, b};
    ll x,y,g;
    tie(x,y,g) = extgcd(b%a, a);
    return {y-b/a*x, x, g};
}

void solve(){
    ll n,s,k;
    cin >> n >> s >> k;
    ll x,y,g;
    tie(x,y,g) = extgcd(k,n);
    if(s%g!=0){
        cout << -1 << endl;
        return;
    }
    n/=g;
    s/=g;
    k/=g;
    ll ans = ((x*-s)%n+n)%n;
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
}