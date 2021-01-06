/**
*    author:  shu8Cream
*    created: 06.01.2021 00:15:37
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

vi to[100100];
int dp[100100];

int rec(int v){
    if(dp[v]!=-1) return dp[v];
    int res = 0;
    for(auto nv : to[v]){
        res=max(res, rec(nv)+1);
    }
    return dp[v]=res;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    rep(i,m){
        int x,y;
        cin >> x >> y;
        x--; y--;
        to[x].push_back(y);
    }

    rep(i,n) dp[i]=-1;

    int ans = 0;
    rep(i,n) ans=max(ans, rec(i));
    cout << ans << endl;
}