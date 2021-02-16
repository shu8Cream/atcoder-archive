/**
*    author:  shu8Cream
*    created: 16.02.2021 12:01:45
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

vector<ll> divisor(ll n) {
    vector<ll> ret;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end()); // 昇順に並べる
    return ret;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,m;
    cin >> n >> m;
    auto div = divisor(m);
    ll ans = 1;
    for(auto p : div){
        if(p*n<=m) ans=max(ans, p);
    }
    cout << ans << endl;
}