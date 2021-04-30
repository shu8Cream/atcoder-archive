/**
*    author:  shu8Cream
*    created: 30.04.2021 13:09:29
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
    int n;
    cin >> n;
    vvi field(1005,vi(1005));
    rep(i,n){
        int lx,rx,ly,ry;
        cin >> lx >> ly >> rx >> ry;
        field[lx][ly]++;
        field[rx][ry]++;
        field[lx][ry]--;
        field[rx][ly]--;
    }

    rep(i,1005)for(int j=1; j<1005; j++) {
        field[i][j] += field[i][j - 1];
    }
    for(int i=1; i<1005; i++)rep(j,1005){
        field[i][j] += field[i-1][j];
    }

    vi ans(n+1);
    rep(i,1005)rep(j,1005){
        if(!field[i][j]) continue;
        ans[field[i][j]]++;
    }
    rep(i,n) cout << ans[i+1] << endl;
}