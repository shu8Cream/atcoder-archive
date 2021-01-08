/**
*    author:  shu8Cream
*    created: 08.01.2021 16:02:03
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
    double a,b,x;
    cin >> a >> b >> x;
    double h = x/a/a;
    double ans;
    if(b>=2*(b-h)) ans = (b-h)*2 / a ;
    else ans = b / (2*x/a/b);
    printf("%.10lf\n", atan(ans)*180/M_PI);
}