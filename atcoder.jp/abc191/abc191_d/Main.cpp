/**
*    author:  shu8Cream
*    created: 10.02.2021 14:49:34
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
    long double x,y,r;
    cin >> x >> y >> r;
    ll ans = 0;
    r = nextafter(r,INFINITY);
    ll s = ceil(x-r), e = floor(x+r);
    for(ll i=s; i<=e; i++){
        long double d = sqrt(r*r-(x-i)*(x-i));
        ll ss = ceil(y-d), ee = floor(y+d);
        ans+=ee-ss+1;
    }
    cout << ans << endl;
}
