/**
*    author:  shu8Cream
*    created: 29.03.2021 14:19:17
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

const int INF = 1001001001;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vector<vector<P>> to(n);
    rep(i,m){
        int a,b; char c;
        cin >> a >> b >> c;
        a--; b--;
        to[a].emplace_back(b,c-'a');
        to[b].emplace_back(a,c-'a');
    }

    vvi dp(n, vi(n,INF));
    queue<P> q;

    auto push = [&](int a, int b, int x) {
        if (dp[a][b] != INF) return;
        dp[a][b] = x;
        q.emplace(a,b);
    };
    
    push(0,n-1,0);
    while(!q.empty()){
        auto [a,b] = q.front(); q.pop();
        for(auto ea : to[a])for(auto eb : to[b]){
            if(ea.second!=eb.second) continue;
            push(ea.first, eb.first, dp[a][b]+1);
        }
    }

    int ans = INF;
    rep(i,n){
        ans = min(ans,dp[i][i]*2);
        for(auto e : to[i]){
            ans = min(ans, dp[i][e.first]*2+1);
        }
    }
    if(ans==INF) ans = -1;
    cout << ans << endl;
}