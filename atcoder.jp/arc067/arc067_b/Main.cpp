/**
*    author:  shu8Cream
*    created: 05.03.2021 11:51:23
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,a,b;
    cin >> n >> a >> b;
    vector<ll> x(n), r(n);
    rep(i,n){
        cin >> x[i];
        if(i) r[i]=x[i]-x[i-1];
    }
    ll ans = 0;
    rep(i,n){
        if(i) ans+=min(r[i]*a, b);
    }
    cout << ans << endl;
}