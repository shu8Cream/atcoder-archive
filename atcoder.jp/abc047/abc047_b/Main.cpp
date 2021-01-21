/**
*    author:  shu8Cream
*    created: 21.01.2021 19:15:33
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
    int w,h,n;
    cin >> w >> h >> n;
    int lx=0, rx=w, uy=h, by=0;
    rep(i,n){
        int x,y,a;
        cin >> x >> y >> a;
        if(a==1) lx=max(lx,x);
        if(a==2) rx=min(rx,x);
        if(a==3) by=max(by,y);
        if(a==4) uy=min(uy,y);
    }
    int ans = max(rx-lx, 0) * max(uy-by, 0);
    cout << ans << endl;
}