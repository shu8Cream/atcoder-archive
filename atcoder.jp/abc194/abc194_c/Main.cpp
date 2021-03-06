/**
*    author:  shu8Cream
*    created: 06.03.2021 20:47:50
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
    vector<ll> a(n),aa(n),ra(n+1),raa(n+1);
    rep(i,n){
        cin >> a[i];
        aa[i]=a[i]*a[i];
        ra[i+1]=ra[i]+a[i];
        raa[i+1]=raa[i]+aa[i];
    }
    ll ans = 0;
    for(int i=1; i<n; i++){
        ans+=aa[i-1]*(n-i+1)+raa[n]-raa[i-1]-2*a[i-1]*(ra[n]-ra[i-1]);
    }
    cout << ans << endl;
}