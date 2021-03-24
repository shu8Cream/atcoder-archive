/**
*    author:  shu8Cream
*    created: 24.03.2021 10:20:45
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
    ll a,b,c,k;
    cin >> a >> b >> c >> k;
    k&=1;
    if(k) swap(a,b);
    ll ans = a-b;
    cout << ans << endl;
}