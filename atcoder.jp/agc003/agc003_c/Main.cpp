/**
*    author:  shu8Cream
*    created: 13.05.2021 00:50:23
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
    int n; cin >> n;
    vi a(n); rep(i,n) cin >> a[i];
    auto b = a;
    sort(all(b));
    int ans = 0;
    set<int> s;
    rep(i,n) if(i%2==0) s.insert(a[i]);
    rep(i,n) if(i%2==1 && s.count(b[i])) ans++;
    cout << ans << endl;
}