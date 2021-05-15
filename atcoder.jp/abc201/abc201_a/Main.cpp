/**
*    author:  shu8Cream
*    created: 15.05.2021 20:32:33
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    vi a(3);
    rep(i,3) cin >> a[i];
    sort(all(a));
    bool ok = false;
    if(a[1]-a[0]==a[2]-a[1]) ok = true;
    cout << (ok ? "Yes" : "No") << endl;
}