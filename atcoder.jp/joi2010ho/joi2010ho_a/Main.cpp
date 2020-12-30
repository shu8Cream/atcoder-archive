/**
*    author:  shu8Cream
*    created: 30.12.2020 11:23:48
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using vi = vector<int>;

const int mod = 100000;

int main() {
    int n,m;
    cin >> n >> m;
    vi s(n-1),a(m),r(n);
    rep(i,n-1) cin >> s[i];
    rep(i,m) cin >> a[i];
    rep(i,n-1) r[i+1]=r[i]+s[i]; 
    int ans = 0;
    int now = 0;
    rep(i,m){
        int next = now + a[i];
        ans=(ans+abs(r[next]-r[now]))%mod;
        now = next;
    }
    cout << ans << endl;
}