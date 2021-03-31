/**
*    author:  shu8Cream
*    created: 31.03.2021 16:39:01
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

int n,z,w;
vi a;
vvi memo(2020,vi(2,-1));
int dfs(int i, int t){
    if(memo[i][t]!=-1) return memo[i][t];
    memo[i][t] = abs(a[i]-a[n]);
    for(int j=i+1; j<n; j++){
        if(t) memo[i][t] = min(memo[i][t], dfs(j,t^1));
        else memo[i][t] = max(memo[i][t], dfs(j,t^1));
    }
    return memo[i][t];
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> z >> w;
    a.resize(n+1);
    a[0]=w;
    rep(i,n) cin >> a[i+1];
    cout << dfs(0,0) << endl;
}