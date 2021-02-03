/**
*    author:  shu8Cream
*    created: 03.02.2021 11:04:15
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
    int a,b,c;
    cin >> a >> b >> c;
    int m = max({a,b,c});
    int ans = a+b+c-m+m*10;
    cout << ans << endl;
}