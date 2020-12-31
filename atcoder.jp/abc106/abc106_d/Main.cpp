/**
*    author:  shu8Cream
*    created: 30.12.2020 23:34:48
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
    int n,m,Q;
    cin >> n >> m >> Q;
    vvi a(n, vi(n));
    rep(i,m){
        int l,r;
        cin >> l >> r;
        l--;r--;
        a[l][r]++;
    }
    vvi s(n+1, vi(n+1));
    rep(i,n)rep(j,n){
        s[i+1][j+1]=s[i][j+1]+s[i+1][j]-s[i][j]+a[i][j];
    }
    rep(i,Q){
        int p,q;
        cin >> p >> q;
        p--;//q--;
        cout << s[q][q]-s[p][q]-s[q][p]+s[p][p] << endl;
    }
    
}