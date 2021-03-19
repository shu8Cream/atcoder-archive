/**
*    author:  shu8Cream
*    created: 19.03.2021 12:53:11
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
    ll x,y;
    cin >> x >> y;
    ll ans = abs(abs(x)-abs(y));
    if(x*y>=0 && x<=y) ans+=0;
    if(x*y<0 && x<=y) ans++;
    if(x*y>0 && x>y) ans+=2;
    if(x*y<=0 && x>y) ans++;
    cout << ans << endl;
}