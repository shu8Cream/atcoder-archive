/**
*    author:  shu8Cream
*    created: 16.03.2021 19:54:23
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
    int n,m,x;
    cin >> n >> m >> x;
    vi a(n+1);
    rep(i,m){
        int c; cin >> c;
        a[c]++;
    }
    vi ra(n+2);
    rep(i,n+1) ra[i+1]=ra[i]+a[i];
    int ans = min(ra[x]-ra[0],ra[n+1]-ra[x]);
    cout << ans << endl;
}