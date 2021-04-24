/**
*    author:  shu8Cream
*    created: 24.04.2021 20:47:40
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vi a(n),b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    int ans = 0;
    rep(i,1000){
        bool ok = true;
        rep(j,n){
            if(!(a[j]<=i+1 && i+1<=b[j])) ok = false;
        }
        if(ok) ans++;
    }
    cout << ans << endl;
}