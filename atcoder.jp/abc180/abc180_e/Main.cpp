/**
*    author:  shu8Cream
*    created: 13.12.2020 16:20:05
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;
void chmin(int &x, int y){ x = min(x,y); }

const int INF = 1e9+7;
int dist[21][21];

int main() {
    int n;
    cin >> n;
    vector<tuple<int,int,int>> a(n);
    rep(i,n){
        int x,y,z;
        cin >> x >> y >> z;
        a[i]=make_tuple(x,y,z);
    }
    rep(i,n)rep(j,n){
        int x1,y1,z1;
        tie(x1,y1,z1)=a[i];
        int x2,y2,z2;
        tie(x2,y2,z2)=a[j];
        dist[i][j]=abs(x1-x2)+abs(y1-y2)+max(0,z2-z1);
    }

    int n2 = 1<<n;
    vvi dp(n2,vi(n,INF));
    rep(i,n){
        if(i==0) continue;
        dp[1<<i][i]=dist[0][i];
    }
    rep(i,n2)rep(j,n){
        if(~i>>j&1) continue;
        rep(k,n){
            if(i>>k&1) continue;
            chmin(dp[i|1<<k][k], dp[i][j]+dist[j][k]);
        }
    }

    cout << dp[n2-1][0] << endl;
}