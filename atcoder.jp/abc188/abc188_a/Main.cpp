/**
*    author:  shu8Cream
*    created: 10.01.2021 20:37:59
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
    int x,y;
    cin >> x >> y;
    cout << (min(x,y)+3 > max(x,y) ? "Yes" : "No") << endl;
}