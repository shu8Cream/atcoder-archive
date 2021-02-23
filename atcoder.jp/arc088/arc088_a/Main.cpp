/**
*    author:  shu8Cream
*    created: 23.02.2021 22:53:55
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
    ll x,y;
    cin >> x >> y;
    int ans = 0;
    ll z = y/x;
    while(z>0){
        z/=2;
        ans++;
    }
    cout << ans << endl;
}