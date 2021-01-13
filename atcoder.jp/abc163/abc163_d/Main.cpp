/**
*    author:  shu8Cream
*    created: 13.01.2021 16:33:24
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

const int mod = 1e9+7;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    ll ans = 0;
    for(ll i=k; i<n+2; i++){
        ll first = i*(i-1)/2;
        ll last = i*(2*n-i+1)/2;
        ans+=last-first+1;
        ans%=mod;
    }
    cout << ans << endl;
}