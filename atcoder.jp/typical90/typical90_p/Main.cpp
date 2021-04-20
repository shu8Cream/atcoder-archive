/**
*    author:  shu8Cream
*    created: 16.04.2021 18:59:35
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
    ll n,a,b,c;
    cin >> n >> a >> b >> c;
    ll ans = 10000;
    rep(i,10000)rep(j,10000){
        if((n-a*i-b*j)>=0 && (n-a*i-b*j)%c==0){
            ans=min(ans,i+j+(n-a*i-b*j)/c);
        }
    }
    cout << ans << endl;
}