/**
*    author:  shu8Cream
*    created: 17.04.2021 15:45:48
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (double i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    double x,y,z;
    cin >> x >> y >> z;
    int ans = 0;
    rep(i,10000000){
        if(y/x>i/z) ans=i;
    }
    cout << ans << endl;
}