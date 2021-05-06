/**
*    author:  shu8Cream
*    created: 06.05.2021 20:31:46
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vi a(n),b(n);
    rep(i,n) cin >> a[i] >> b[i];
    sort(all(a)); sort(all(b));
    if(n%2==1){
        ll m = a[n/2], M = b[n/2];
        cout << M - m + 1 << endl;
    }else{
        ll m = a[n/2-1] + a[n/2];
        ll M = b[n/2-1] + b[n/2];
        cout << M - m + 1 << endl;
    }
}