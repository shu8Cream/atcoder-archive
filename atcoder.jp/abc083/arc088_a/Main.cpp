/**
*    author:  shu8Cream
*    created: 11.04.2021 11:30:30
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
    ll tmp = x;
    while(tmp<=y){
        ans++;
        tmp*=2;
    }
    cout << ans << endl;
}