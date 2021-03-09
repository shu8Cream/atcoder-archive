/**
*    author:  shu8Cream
*    created: 09.03.2021 19:35:34
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
    ll r,b,x,y;
    cin >> r >> b >> x >> y;
    ll ng = 8e18;
    ll ok = -1;
    while(abs(ok-ng)>1){
        ll mid = (ok + ng)/2;
        if(r-mid<0 || b-mid<0){
            ng = mid;
            continue;
        }
        ll s = (r - mid) / (x-1);
        ll t = (b - mid) / (y-1);
        if(s+t>=mid) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
}