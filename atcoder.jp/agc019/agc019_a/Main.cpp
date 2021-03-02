/**
*    author:  shu8Cream
*    created: 02.03.2021 11:36:53
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
    ll q,h,s,d,n;
    cin >> q >> h >> s >> d >> n;
    ll saiyasu = min({q*8,h*4,s*2,d});
    ll ans = n/2*saiyasu;
    if(n%2==1) ans+=min({q*4,h*2,s});
    cout << ans << endl;
}