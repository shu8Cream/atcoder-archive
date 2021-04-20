/**
*    author:  shu8Cream
*    created: 02.04.2021 18:47:41
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
    int h,w;
    cin >> h >> w;
    vvi a(h,vi(w));
    rep(i,h)rep(j,w) cin >> a[i][j];
    vi col(h),row(w);
    rep(i,h)rep(j,w) col[i]+=a[i][j];
    rep(i,w)rep(j,h) row[i]+=a[j][i];
    vvi ans(h,vi(w));
    rep(i,h)rep(j,w) ans[i][j]=col[i]+row[j]-a[i][j];
    rep(i,h){
        cout << ans[i][0];
        rep(j,w-1) cout << " " << ans[i][j+1];
        cout << endl;
    }
}