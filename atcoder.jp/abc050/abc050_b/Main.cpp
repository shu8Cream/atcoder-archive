/**
*    author:  shu8Cream
*    created: 05.03.2021 20:21:40
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
    vi t(n);
    rep(i,n) cin >> t[i];
    int m; cin >> m;
    int sum = 0;
    rep(i,n) sum+=t[i];
    rep(i,m){
        int p,x;
        cin >> p >> x;
        int ans = sum-t[p-1]+x;
        cout << ans << endl;
    }
}