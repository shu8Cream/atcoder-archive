/**
*    author:  shu8Cream
*    created: 20.03.2021 14:02:07
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
    ll n;
    cin >> n;
    vector<ll> h(n),s(n);
    rep(i,n) cin >> h[i] >> s[i];
    ll ok = 1e18, ng = -1;
    while(ok-ng>1){
        ll mid = (ng + ok)/2;
        vi a(n);
        bool f = true;
        rep(i,n){
            if(mid<h[i]) f = false;
            else a[min(n-1, (mid-h[i])/s[i])]++;
        }
        rep(i,n-1) a[i+1]+=a[i];
        rep(i,n) if(a[i]>i+1) f = false;
        if(f) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
}