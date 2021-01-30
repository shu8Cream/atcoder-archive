/**
*    author:  shu8Cream
*    created: 30.01.2021 20:42:05
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
    vi a(m),b(m);
    rep(i,m) cin >> a[i] >> b[i];
    int k; cin >> k;
    vi c(k),d(k);
    rep(i,k) cin >> c[i] >> d[i];
    ll ans = 0;
    rep(s,1<<k){
        ll tmp=0;
        vi sara(n);
        rep(i,k){
            if(s>>i&1) sara[c[i]-1]=1;
            else sara[d[i]-1]=1;
        }
        rep(i,m){
            if(sara[a[i]-1] && sara[b[i]-1]) tmp++;
        }
        ans=max(ans,tmp);
    }
    cout << ans << endl;
}