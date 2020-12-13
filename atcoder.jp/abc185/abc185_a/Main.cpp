/**
*    author:  shu8Cream
*    created: 13.12.2020 20:58:43
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;

int main() {
    vi a(4);
    rep(i,4) cin >> a[i];
    int ans = min({a[0], a[1], a[2], a[3]});
    cout << ans << endl;
}