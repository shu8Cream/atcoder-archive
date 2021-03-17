/**
*    author:  shu8Cream
*    created: 17.03.2021 10:02:50
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
    vector<ll> a(n),ra(n+1);
    rep(i,n){
        cin >> a[i];
        ra[i+1]=(ra[i]+a[i])%m;
    }
    ll ans = 0;
    map<ll,ll> mp;
    rep(i,n) mp[ra[i+1]]++;
    for(auto [k,v] : mp){
        if(k==0) ans+=v;
        ans+=v*(v-1)/2;
    }
    cout << ans << endl;
}