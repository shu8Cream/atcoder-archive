/**
*    author:  shu8Cream
*    created: 24.03.2021 14:41:32
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
    ll a,b,c;
    cin >> a >> b >> c;
    if(a>b) swap(a,b);
    if(b>c) swap(b,c);
    ll ans = a*b*((c+1)/2-c/2);
    cout << ans << endl;
}