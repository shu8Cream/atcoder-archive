/**
*    author:  shu8Cream
*    created: 27.02.2021 20:10:49
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
    vi a(n),p(n),x(n);
    rep(i,n) cin >> a[i] >> p[i] >> x[i];
    int ans = 1e9+7;
    rep(i,n){
        if(x[i]-a[i]>0) ans=min(ans,p[i]);
    }
    if(ans==1e9+7) cout << -1 << endl;
    else cout << ans << endl;
}