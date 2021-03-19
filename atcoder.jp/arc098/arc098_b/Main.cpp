/**
*    author:  shu8Cream
*    created: 19.03.2021 14:35:21
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
    vector<ll> sum(n+1), xorsum(n+1);
    rep(i,n){
        sum[i+1]=sum[i]+a[i];
        xorsum[i+1]=xorsum[i]^a[i];
    }
    ll ans = 0;
    rep(i,n){
        int ok = i, ng = n+1;
        while(ng-ok>1){
            int mid = (ok + ng) / 2;
            if(sum[mid]-sum[i] == (xorsum[mid]^xorsum[i])){
                ok = mid;
            }else ng = mid;
        }
        ans+=ok-i;
    }
    cout << ans << endl;
}