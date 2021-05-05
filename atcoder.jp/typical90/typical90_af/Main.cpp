/**
*    author:  shu8Cream
*    created: 05.05.2021 15:57:50
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

const int INF = 1001001001;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vvi a(n, vi(n));
    rep(i,n)rep(j,n) cin >> a[i][j];
    int m; cin >> m;
    vi x(m),y(m);
    rep(i,m){
        cin >> x[i] >> y[i];
        x[i]--; y[i]--;
    }
    vector<int> idx(n);
    rep(i,n) idx[i]=i;
    int ans = INF;
    do{
        int tmp = 0;
        bool f = true;
        rep(i,n-1)rep(j,m){
            if(idx[i]==x[j] && idx[i+1]==y[j]) f = false;
            if(idx[i]==y[j] && idx[i+1]==x[j]) f = false;
        }
        if(!f) continue;
        rep(i,n) tmp+=a[idx[i]][i];
        ans = min(ans, tmp);
    }while(next_permutation(all(idx)));
    if(ans==INF) ans = -1;
    cout << ans << endl;
}