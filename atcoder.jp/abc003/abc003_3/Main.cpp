/**
*    author:  shu8Cream
*    created: 23.12.2020 20:57:17
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
using vi = vector<int>;

int main() {
    int n,k;
    cin >> n >> k;
    vi r(n);
    rep(i,n) cin >> r[i];
    sort(r.begin(), r.end());
    double ans = 0;
    rep(i,k){
        ans=(ans+r[i+n-k])/2;
    }
    printf("%.10lf\n", ans);
}