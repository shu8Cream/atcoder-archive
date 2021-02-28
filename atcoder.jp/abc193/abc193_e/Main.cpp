/**
*    author:  shu8Cream
*    created: 27.02.2021 20:11:23
**/

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

tuple<ll, ll, ll> extgcd(ll a, ll b){
    if(a == 0) return {0, 1, b};
    ll x,y,g;
    tie(x,y,g) = extgcd(b%a, a);
    return {y-b/a*x, x, g};
}

ll CRT(ll mod1, ll a, ll mod2, ll b){
    ll k,l,m;
    tie(k,l,m) = extgcd(mod1, mod2);
    ll g = mod1*k + mod2*l;
    if((b-a)%g!=0) return -1;
    k*=(b-a)/g;
    ll ans = mod1*k+a;
    ll lcm = mod1 * mod2 / g;
    return ans%lcm;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        ll x,y,p,q;
        cin >> x >> y >> p >> q;
        ll mod1 = 2*(x+y);
        ll mod2 = p+q;
        ll ans = 9e18;
        for(ll i=p; i<p+q; i++){
            //ll tmp = CRT(mod1, x, mod2, i);
            //if(tmp==-1) continue;
            //ans = min(ans,tmp);
            auto tmp = crt({x,i}, {mod1, mod2});
            if(tmp.second==0) continue;
            ans = min(ans,tmp.first);
        }
        for(ll i=x; i<x+y; i++){
            //ll tmp = CRT(mod1, i, mod2, p);
            //if(tmp==-1) continue;
            //ans = min(ans,tmp);
            auto tmp = crt({i,p}, {mod1, mod2});
            if(tmp.second==0) continue;
            ans = min(ans,tmp.first);
        }
        if(ans==9e18) cout << "infinity" << endl;
        else cout << ans << endl;
    }
}