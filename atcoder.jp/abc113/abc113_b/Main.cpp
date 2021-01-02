/**
*    author:  shu8Cream
*    created: 02.01.2021 18:59:34
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()

int main() {
    int n;
    double t,a;
    cin >> n >> t >> a;
    vector<double> h(n);
    rep(i,n) cin >> h[i];
    double tmp=1000;
    int ans=0;
    rep(i,n){
        tmp=min(tmp, abs(t-h[i]*0.006-a));
        if(tmp==abs(t-h[i]*0.006-a)) ans=i+1;
    }
    cout << ans << endl;
}