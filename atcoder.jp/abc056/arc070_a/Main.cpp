/**
*    author:  shu8Cream
*    created: 26.01.2021 00:12:40
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
    int x;
    cin >> x;
    vector<ll> r(100000);
    rep(i,100000) r[i+1]=r[i]+(i+1);
    int ans = lower_bound(all(r), x) - r.begin();
    cout << ans << endl;
}