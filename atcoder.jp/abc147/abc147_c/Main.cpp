/**
*    author:  shu8Cream
*    created: 08.05.2021 17:06:06
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<vector<P>> a(n); 
    rep(i,n){
        int m; cin >> m;
        rep(j,m){
            int x,y; cin >> x >> y;
            a[i].push_back({x-1,y});
        }
    }
    int ans = 0;
    rep(b,1<<n){
        bool ok = true;
        int tmp = 0;
        rep(i,n){
            if(b>>i&1){
                tmp++;
                for(auto [f,s] : a[i]){
                    if((b>>f&1)!=s) ok = false;
                }
            }
        }
        if(ok) ans = max(ans, tmp);
    }
    cout << ans << endl;
}