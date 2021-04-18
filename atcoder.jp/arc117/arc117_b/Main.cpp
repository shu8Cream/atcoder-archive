/**
*    author:  shu8Cream
*    created: 18.04.2021 20:52:26
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

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vi a(n); rep(i,n) cin >> a[i];
    sort(all(a));
    ll ans = 1;
    rep(i,n-1){
        ans*=a[i+1]-a[i]+1;
        ans%=mod;
    }
    ans*=a[0]+1;
    ans%=mod;
    cout << ans << endl;
}