/**
*    author:  shu8Cream
*    created: 26.01.2021 16:23:37
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).rbegin(), (x).rend()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,h;
    cin >> n >> h;
    vector<ll> a(n),b(n);
    ll amax = 0;
    rep(i,n){
        cin >> a[i] >> b[i];
        amax=max(amax,a[i]);
    }
    sort(all(b));
    ll ans = 0;
    rep(i,n){
        if(b[i]>amax){
            h-=b[i];
            ans++;
            if(h<=0) break;
        }
    }
    if(h>0) ans+=(h+amax-1)/amax;
    cout << ans << endl;
}