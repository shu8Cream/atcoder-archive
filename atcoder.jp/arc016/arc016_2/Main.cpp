/**
*    author:  shu8Cream
*    created: 22.03.2021 23:06:36
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
    vector<string> x(n);
    rep(i,n) cin >> x[i];
    int ans = 0;
    rep(j,9)rep(i,n){
        if(x[i][j]=='x') ans++;
        if(i==0 && x[i][j]=='o') ans++;
        if(i!=n-1 && x[i][j]!='o' && x[i+1][j]=='o') ans++;
    }
    cout << ans << endl;
}