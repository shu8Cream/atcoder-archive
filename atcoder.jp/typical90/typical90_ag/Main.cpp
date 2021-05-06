/**
*    author:  shu8Cream
*    created: 06.05.2021 20:02:39
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
    int h,w;
    cin >> h >> w;
    int ans = ((h+1)/2) * ((w+1)/2);
    if(h==1 || w==1) ans = h*w;
    cout << ans << endl;
}