/**
*    author:  shu8Cream
*    created: 10.01.2021 20:38:07
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
    vi a(1<<n);
    rep(i,1<<n) cin >> a[i];
    int fmx=0, bmx=0;
    rep(i,1<<(n-1)) fmx=max(fmx,a[i]);
    rep(i,1<<(n-1)) bmx=max(bmx,a[i+pow(2,n-1)]);
    int ans = min(fmx, bmx);
    rep(i,1<<n){
        if(ans==a[i]){
            cout << i+1 << endl;
            return 0;
        }
    }
}