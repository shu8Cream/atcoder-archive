/**
*    author:  shu8Cream
*    created: 08.02.2021 21:48:46
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
    ll ans = 0;
    rep(i,n){
        for(int j=i+1; j<n; j++){
            ans=max(ans, abs(a[i]-a[j]));
        }
    }
    cout << ans << endl;
}