/**
*    author:  shu8Cream
*    created: 19.04.2021 22:21:46
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ld = long double;
using P = pair<ll,ll>;
using vi = vector<ld>;
using vvi = vector<vi>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ld t,l,x,y; int q;
    cin >> t >> l >> x >> y >> q;
    rep(i,q){
        ld e; cin >> e;
        ld kx = -l/2.0 * sin(e/t*2.0*M_PI);
        ld ky = l/2.0 - l/2.0 * cos(e/t*2.0*M_PI);
        ld b = sqrt(x*x+(kx-y)*(kx-y));
        ld ans = atan2(ky,b) * 180.0 / M_PI;
        printf("%.15Lf\n", ans);
    }
}