/**
*    author:  shu8Cream
*    created: 27.03.2021 12:58:59
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
    int n,l;
    cin >> n >> l;
    vector<ll> x(n),a(n),t(n);
    rep(i,n) cin >> x[i] >> a[i];
    ll ans = 0;
    t[0]=-a[0];
    rep(i,n-1){
        t[i+1]=min((ll)0, t[i]+x[i+1]-x[i]);
        t[i+1]-=a[i+1];
    }
    rep(i,n) ans=min(ans,t[i]);
    ans*=-1;
    cout << ans << endl;
}