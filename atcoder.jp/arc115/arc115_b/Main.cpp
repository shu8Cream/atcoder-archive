/**
*    author:  shu8Cream
*    created: 22.03.2021 10:26:54
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<ll>;
using vvi = vector<vi>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vvi c(n,vi(n)),d(n,vi(n));
    ll m = 1e18;
    int cur1 = 0, cur2 = 0;
    rep(i,n)rep(j,n){
        cin >> c[i][j];
        m = min(m, c[i][j]);
        if(m == c[i][j]){
            cur1=i;
            cur2=j;
        }
    }

    vi a(n),b(n);
    rep(i,n) b[i]=c[cur1][i]-m;
    rep(i,n) a[i]=c[i][cur2];
    rep(i,n)rep(j,n) d[i][j]=a[i]+b[j];
    rep(i,n)rep(j,n) if(c[i][j]!=d[i][j]){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    rep(i,n) cout << a[i] << endl;
    rep(i,n) cout << b[i] << endl;
}