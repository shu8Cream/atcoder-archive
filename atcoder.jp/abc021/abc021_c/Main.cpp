/**
*    author:  shu8Cream
*    created: 24.04.2021 15:21:50
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

const int mod = 1e9+7;
const int INF = 1001001001;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,a,b,m;
    cin >> n >> a >> b >> m;
    a--; b--;
    vvi to(n);
    rep(i,m){
        int x,y; cin >> x >> y;
        x--; y--;
        to[x].push_back(y);
        to[y].push_back(x);
    }
    vi dp(n); dp[a]=1;
    vi dist(n,-1);
    queue<int> q;
    dist[a]=0;
    q.push(a);
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(auto nv : to[v]){
            if(dist[nv]==-1){
                dist[nv]=dist[v]+1;
                q.push(nv);
            }
            if(dist[nv]==dist[v]+1)
                dp[nv]=(dp[nv]+dp[v])%mod;
        }
    }
    cout << dp[b] << endl;
}