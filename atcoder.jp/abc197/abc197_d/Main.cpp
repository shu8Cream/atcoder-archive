/**
*    author:  shu8Cream
*    created: 27.03.2021 20:56:44
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
    double n,x0,y0,x2n,y2n;
    cin >> n >> x0 >> y0 >> x2n >> y2n;
    double xm = (x0 + x2n) / 2, ym = (y0 + y2n) / 2;
    x0 -= xm;
    y0 -= ym;
    double rad = 2 * M_PI / n;
    double xans = 0, yans = 0;
    xans = x0 * cos(rad) - y0 * sin(rad);
    yans = x0 * sin(rad) + y0 * cos(rad);
    xans += xm;
    yans += ym;
    printf("%.10lf %.10lf\n", xans,yans);
}