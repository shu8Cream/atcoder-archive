/**
*    author:  shu8Cream
*    created: 26.04.2021 13:25:15
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
    int n,k;
    cin >> n >> k;
    vi a(n),b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    int cnt = 0;
    rep(i,n){
        cnt += abs(a[i]-b[i]);
    }
    cout << (((cnt-k)<=0 && (cnt-k)%2==0) ? "Yes" : "No") << endl;
}