/**
*    author:  shu8Cream
*    created: 15.03.2021 15:36:36
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).rbegin(), (x).rend()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int x,y,z,k;
    cin >> x >> y >> z >> k;
    vector<ll> a(x),b(y),c(z);
    rep(i,x) cin >> a[i];
    rep(i,y) cin >> b[i];
    rep(i,z) cin >> c[i];
    sort(all(a));
    sort(all(b));
    sort(all(c));
    vector<ll> ab,abc;
    rep(i,x)rep(j,y) ab.push_back(a[i]+b[j]);
    sort(all(ab));
    ab.resize(k);
    rep(i,k)rep(j,z) abc.push_back(ab[i]+c[j]);
    sort(all(abc));
    sort(all(abc));
    rep(i,k) cout << abc[i] << endl;
}