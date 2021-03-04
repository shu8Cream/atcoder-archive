/**
*    author:  shu8Cream
*    created: 04.03.2021 20:36:44
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
    vector<ll> a(n),r(n+1);
    rep(i,n){
        cin >> a[i];
        r[i+1]=a[i]+r[i];
    }
    ll ans = 8e18;
    rep(i,n){
        ans=min(ans,abs(r[n]-2*r[i+1]));
    }
    cout << ans << endl;
}