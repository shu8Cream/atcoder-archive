/**
*    author:  shu8Cream
*    created: 14.04.2021 21:11:44
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int h,w,a,b;
    cin >> h >> w >> a >> b;
    vvi ans(h,vi(w));
    rep(i,h){
        rep(j,w){
            if(i<b && a<=j) ans[i][j]=1;
            if(b<=i && j<a) ans[i][j]=1;
        }
    }
    rep(i,h){
        rep(j,w) cout << ans[i][j];
        cout << endl;
    }
}