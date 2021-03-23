/**
*    author:  shu8Cream
*    created: 23.03.2021 21:25:23
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
    int n,d,x;
    cin >> n >> d >> x;
    vi a(n);
    rep(i,n) cin >> a[i];
    int ans = 0;
    rep(i,n){
        ans+=(d-1)/a[i];
    }
    ans+=n+x;
    cout << ans << endl;
}