/**
*    author:  shu8Cream
*    created: 27.03.2021 20:56:14
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
    int h,w,x,y;
    cin >> h >> w >> x >> y;
    x--; y--;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    int ans = 0;
    rep(i,h){
        if(x-i-1>=0 && s[x-i-1][y]=='.') ans++;
        else break;
    }
    rep(i,h){
        if(x+i+1<h && s[x+i+1][y]=='.') ans++;
        else break;
    }
    rep(i,w){
        if(y-i-1>=0 && s[x][y-i-1]=='.') ans++;
        else break;
    }
    rep(i,w){
        if(y+i+1<w && s[x][y+i+1]=='.') ans++;
        else break;
    }
    ans++;
    cout << ans << endl;
}