/**
*    author:  shu8Cream
*    created: 19.12.2020 20:53:59
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;

int main() {
    int h,w;
    cin >> h >> w;
    vvi a(h, vi(w));
    int minc=100;
    rep(i,h)rep(j,w){
        cin >> a[i][j];
        minc=min(minc, a[i][j]);
    }
    int ans = 0;
    rep(i,h)rep(j,w){
        ans+=max(a[i][j]-minc, 0);
    }
    cout << ans << endl;
}