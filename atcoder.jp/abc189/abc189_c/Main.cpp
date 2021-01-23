/**
*    author:  shu8Cream
*    created: 23.01.2021 20:46:57
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
    rep(l,n){
        int x=a[l];
        for(int r=l; r<n; r++){
            x=min(x,a[r]);
            ans=max(ans, (r-l+1)*x);
        }
    }
    cout << ans << endl;
}