/**
*    author:  shu8Cream
*    created: 03.03.2021 18:16:12
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
    int n,k;
    cin >> n >> k;
    vi x(n);
    rep(i,n) cin >> x[i];
    int ans = 0;
    rep(i,n){
        ans+=min(x[i],abs(k-x[i]))*2;
    }
    cout << ans << endl;
}