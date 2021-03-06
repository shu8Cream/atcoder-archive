/**
*    author:  shu8Cream
*    created: 06.03.2021 17:14:07
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
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll ans = a[n-1];
    rep(i,n-1){
        if(a[n-1-i]-a[n-2-i]>1){
            cout << -1 << endl;
            return 0;
        }
        if(a[n-1-i]-a[n-2-i]<=0) ans+=a[n-2-i];
    }
    if(a[0]!=0) ans=-1;
    cout << ans << endl;
}