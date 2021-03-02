/**
*    author:  shu8Cream
*    created: 02.03.2021 20:53:04
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
    int n,m;
    cin >> n >> m;
    vector<ll> h(n),w(m);
    rep(i,n) cin >> h[i];
    rep(i,m) cin >> w[i];
    sort(all(h));
    ll ans = 1e18, tmp = 0;
    vector<ll> l(n+1), r(n+1);
    for(int i=0; i<n-2; i+=2){
        l[i+2]=l[i]+h[i+1]-h[i];
        r[i+2]=r[i]+h[n-i-1]-h[n-i-2];
    }

    rep(i,m){
        auto itr = lower_bound(all(h), w[i]) - h.begin();
        if(itr%2==0) tmp=l[itr]+r[n-itr-1]+abs(h[itr]-w[i]);
        else tmp=l[itr-1]+r[n-itr]+abs(h[itr-1]-w[i]);
        ans=min(ans,tmp);
    }
    cout << ans << endl;
}