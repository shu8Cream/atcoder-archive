/**
*    author:  shu8Cream
*    created: 27.12.2020 11:19:50
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n), ans(n);
    rep(i,n) cin >> a[i];
    rep(i,n){
        if(i%2==0) ans[0]+=a[i];
        else ans[0]-=a[i];
    }
    if(ans[0]<0) ans[0]*=-1;
    rep(i,n-1){
        ans[i+1]=(a[i]-ans[i]/2)*2;
    }
    rep(i,n) cout << ans[i] << endl;
}