/**
*    author:  shu8Cream
*    created: 17.02.2021 00:11:57
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
    int n;
    cin >> n;
    vi a(n);
    rep(i,n) cin >> a[i];
    sort(all(a));
    int ans = 0;
    rep(i,n){
        int c = upper_bound(all(a), a[i]+2) - a.begin();
        ans=max(ans, c-i);
    }
    cout << ans << endl;
}