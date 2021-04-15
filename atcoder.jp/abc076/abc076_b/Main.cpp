/**
*    author:  shu8Cream
*    created: 15.04.2021 20:58:30
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
    int ans = 1e9;
    rep(s,1<<n){
        int tmp = 1;
        rep(i,n){
            if(s>>i&1) tmp*=2;
            else tmp+=k;
        }
        ans=min(ans,tmp);
    }
    cout << ans << endl;
}