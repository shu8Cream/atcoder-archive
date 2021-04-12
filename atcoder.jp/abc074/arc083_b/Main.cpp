/**
*    author:  shu8Cream
*    created: 12.04.2021 21:42:37
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<ll>;
using vvi = vector<vi>;

const int INF = 1001001001;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vvi a(n,vi(n));
    rep(i,n)rep(j,n) cin >> a[i][j];
    auto d = a;
    rep(i,n)rep(s,n)rep(g,n){
        if(i==s || i==g || s==g) continue;
        if(a[s][i]==INF || a[i][g]==INF) continue;
        if(a[s][i]+a[i][g] == d[s][g]) a[s][g]=INF;
        else if(a[s][i]+a[i][g] < d[s][g]){
            cout << -1 << endl;
            return 0;
        }
    }
    ll ans = 0;
    rep(i,n)rep(j,n) if(a[i][j]!=INF) ans+=a[i][j];
    cout << ans/2 << endl;
}