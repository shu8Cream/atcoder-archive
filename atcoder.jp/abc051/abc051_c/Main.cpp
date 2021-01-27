/**
*    author:  shu8Cream
*    created: 27.01.2021 00:26:40
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
    int sx,sy,tx,ty;
    cin >> sx >> sy >> tx >> ty;
    string ans;
    rep(i,ty-sy) ans+='U';
    rep(i,tx-sx) ans+='R';
    rep(i,ty-sy) ans+='D';
    rep(i,tx-sx) ans+='L';
    ans+='L';
    rep(i,ty-sy+1) ans+='U';
    rep(i,tx-sx+1) ans+='R';
    ans+='D';
    ans+='R';
    rep(i,ty-sy+1) ans+='D';
    rep(i,tx-sx+1) ans+='L';
    ans+='U';
    cout << ans << endl;
}