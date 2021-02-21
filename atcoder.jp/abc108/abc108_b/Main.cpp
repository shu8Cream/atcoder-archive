/**
*    author:  shu8Cream
*    created: 21.02.2021 18:40:27
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
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int nx = x2-x1;
    int ny = y2-y1;
    int x3, y3, x4, y4;
    x3 = x2 - ny;
    y3 = y2 + nx;
    x4 = x1 - ny;
    y4 = y1 + nx;
    printf("%d %d %d %d\n", x3,y3,x4,y4);
}