/**
*    author:  shu8Cream
*    created: 11.03.2021 23:56:40
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
    int n;
    cin >> n;
    int x = 800 * n;
    int y = n/15 * 200;
    int ans = x-y;
    cout << ans << endl;
}