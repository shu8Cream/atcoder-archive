/**
*    author:  shu8Cream
*    created: 17.02.2021 21:19:57
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
    int n,m;
    cin >> n >> m;
    vi a(n),b(n);
    rep(i,n) cin >> a[i] >> b[i];
    vi c(m),d(m);
    rep(i,m) cin >> c[i] >> d[i];
    rep(i,n){
        int ans, tmp=1e9;
        rep(j,m){
            tmp=min(tmp, abs(a[i]-c[j])+abs(b[i]-d[j]));
        }
        rep(j,m){
            if(tmp==abs(a[i]-c[j])+abs(b[i]-d[j])){
                ans=j+1;
                break;
            }
        }
        cout << ans << endl;
    }
}