/**
*    author:  shu8Cream
*    created: 05.03.2021 20:03:14
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
    int h,w;
    cin >> h >> w;
    vector<string> c(h);
    vector<vector<char>> nc(2*h, vector<char>(w));
    rep(i,h) cin >> c[i];
    rep(i,2*h)rep(j,w){
        nc[i][j]=c[i/2][j];
    }
    rep(i,2*h){
        rep(j,w) cout << nc[i][j]; 
        cout << endl;
    }
}