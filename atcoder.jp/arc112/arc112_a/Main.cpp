/**
*    author:  shu8Cream
*    created: 13.02.2021 20:47:49
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
    int t;
    cin >> t;
    while(t--){
        ll l,r;
        cin >> l >> r;
        ll ans = 0;
        ll s = ((r+1)/2 - l) * 2;
        if(((r-l)%2)==(l%2)) s++;
        if(((r+1)/2 - l)<0) s=0;
        ans=(s+1)*s/2;
        cout << ans << endl;
    }
}