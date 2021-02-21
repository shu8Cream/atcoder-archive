/**
*    author:  shu8Cream
*    created: 21.02.2021 17:43:44
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
    vi a(n);
    rep(i,n) cin >> a[i];
    int ans = 0;
    rep(i,n){
        while(a[i]%2==0){
            ans++;
            a[i]/=2;
        }
    }
    cout << ans << endl;
}