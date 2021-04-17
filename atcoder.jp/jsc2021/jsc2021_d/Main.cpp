/**
*    author:  shu8Cream
*    created: 17.04.2021 15:46:26
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

const int mod = 1e9+7;

ll mod_pow(ll a, ll b, ll n){
    if(b==0) return 1;
    if(b%2!=0) return a * mod_pow(a, b-1, n) % n;
    else return mod_pow(a * a % n, b / 2, n) % n;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,p;
    cin >> n >> p;
    ll ans = p-1;
    ans *= mod_pow(p-2, n-1, mod);
    ans %= mod;
    cout << ans << endl;
}