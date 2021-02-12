/**
*    author:  shu8Cream
*    created: 12.02.2021 13:44:01
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
    ll n;
    cin >> n;
    ll ans = (n+10)/11*2;
    if(n%11<=6) ans--;
    if(n%11==0) ans++;
    cout << ans << endl;
}