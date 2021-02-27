/**
*    author:  shu8Cream
*    created: 27.02.2021 20:10:42
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
    double a,b;
    cin >> a >> b;
    double ans = (double)1-b/a;
    printf("%.10lf\n", ans*100);
}