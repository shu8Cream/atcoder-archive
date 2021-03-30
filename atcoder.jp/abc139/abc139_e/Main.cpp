/**
*    author:  shu8Cream
*    created: 29.03.2021 22:01:23
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

const int MAXN = 1005;
const int MAXV = MAXN*(MAXN-1)/2;
vi to[MAXV];
int id[MAXN][MAXN]; 
int toId(int i, int j){
    if(i>j) swap(i,j);
    return id[i][j];
}

int dp[MAXV];
bool calc[MAXV];
int dfs(int v){
    if(dp[v]!=0){
        if(!calc[v]) return -1;
        return dp[v];
    }
    dp[v] = 1;
    for(auto u : to[v]){
        int res = dfs(u);
        if(res == -1) return -1;
        dp[v] = max(dp[v], res+1);
    }
    calc[v] = 1;
    return dp[v];
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vvi a(n,vi(n-1));
    rep(i,n)rep(j,n-1){
        cin >> a[i][j];
        a[i][j]--;
    }
    int idnum = 0;
    rep(i,n)rep(j,n){
        if(i<j) id[i][j]=idnum++;
    }
    rep(i,n){
        rep(j,n-1) a[i][j]=toId(i,a[i][j]);
        rep(j,n-2) to[a[i][j+1]].push_back(a[i][j]);
    }
    int ans = 0;
    rep(i,idnum){
        int res = dfs(i);
        if(res == -1){
            cout << res << endl;
            return 0;
        }
        ans = max(ans, res);
    }
    cout << ans << endl;
}