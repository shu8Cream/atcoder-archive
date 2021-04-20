/**
*    author:  shu8Cream
*    created: 06.04.2021 19:22:22
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<ll>;
using vvi = vector<vi>;

const ll INF = 8e18;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vi a(n+2); rep(i,n) cin >> a[i];
    a[n]=INF; a[n+1]=-INF;
    int q; cin >> q;
    vi b(q); rep(i,q) cin >> b[i];
    sort(all(a));
    ll ans = 0;
    rep(i,q){
        int t = lower_bound(all(a), b[i]) - a.begin();

        ans=min(abs(a[t]-b[i]), abs(a[t-1]-b[i]));
        cout << ans << endl;
    }
}