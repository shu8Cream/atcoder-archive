/**
*    author:  shu8Cream
*    created: 10.05.2021 20:31:09
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m,t;
    cin >> n >> m >> t;
    vi a(n); rep(i,n) cin >> a[i];
    int ans = 0;
    rep(i,n){
        if(!i) ans+=a[i]-m;
        else ans+=max(a[i]-a[i-1]-2*m,0);
    }
    ans+=max(t-a[n-1]-m,0);
    cout << ans << endl;
}